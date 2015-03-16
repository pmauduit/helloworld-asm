# stolen from / inspired from http://www.tutorialspoint.com/assembly_programming/assembly_memory_management.htm

section .text
    global _start
_start:
  mov   eax, 45
  xor   ebx, ebx        ; Why first calling sys_brk with 0 as argument in ebx ?
  int   80h
  add   eax, 16384      ;number of bytes to be reserved
  mov   ebx, eax
  mov   eax, 45         ;sys_brk
  int   80h
  cmp   eax, 0
  jl    exit    ;exit, if error 
  mov   edi, eax        ;EDI = highest available address
  sub   edi, 4          ;pointing to the last DWORD  
  mov   ecx, 4096       ;number of DWORDs allocated
  xor   eax, eax        ;clear eax
  std                   ;backward ("set direction flag")
  rep   stosd           ;repeat for entire allocated area
  cld                   ;put DF flag to normal state ("clear direction flag")
  mov   eax, 4          ; print
  mov   ebx, 1          ; 1 stdout
  mov   ecx, msg
  mov   edx, len
  int   80h             ;print a message
exit:
  mov   eax, 1
  xor   ebx, ebx
  int   80h
section .data
msg     db      "Allocated 16 kb of memory!", 10
len     equ     $ - msg
