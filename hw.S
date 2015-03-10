section     .text
global      _start                              ;must be declared for linker (ld)

_start:                                         ;tell linker entry point

  mov   rax, 1    ; sys_write
  mov   rdi, 1    ; stdout
  mov   rsi, msg  ; const char * msg
  mov   rdx, len 
  syscall

  mov   rax, 60   ; sys_exit
  mov   rdi, 0    ; error code 0
  syscall

section     .data

msg     db  'Hello, world!',0xa                 ;our string
len     equ $ - msg                             ;length of our string

