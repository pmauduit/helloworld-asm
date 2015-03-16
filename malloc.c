#include <stdio.h>
#include <unistd.h>

int main (void) {
   char * blah = malloc(11);
   blah[0] = 'H';
   blah[10] = '\0';
   blah[1] = 'e';
   blah[2] = 'l';
   blah[3] = 'l';
   blah[4] = 'o';
   blah[5] = 'w';
   blah[6] = 'o';
   blah[7] = 'r';
   blah[8] = 'l';
   blah[9] = 'd';

/* transcribed in asm as:
            0x00400558    488945f8     mov [rbp-0x8], rax
            0x0040055c    488b45f8     mov rax, [rbp-0x8]
            0x00400560    c60048       mov byte [rax], 0x48 ;  0x00000048  -> H
            0x00400563    488b45f8     mov rax, [rbp-0x8]
            0x00400567    4883c00a     add rax, 0xa
            0x0040056b    c60000       mov byte [rax], 0x0 -> '\0'
            0x0040056e    488b45f8     mov rax, [rbp-0x8]
            0x00400572    4883c001     add rax, 0x1
            0x00400576    c60065       mov byte [rax], 0x65 ;  0x00000065  -> e
            0x00400579    488b45f8     mov rax, [rbp-0x8]
            0x0040057d    4883c002     add rax, 0x2
            0x00400581    c6006c       mov byte [rax], 0x6c ;  0x0000006c  -> l
            0x00400584    488b45f8     mov rax, [rbp-0x8]
            0x00400588    4883c003     add rax, 0x3
            0x0040058c    c6006c       mov byte [rax], 0x6c ;  0x0000006c  -> l
            0x0040058f    488b45f8     mov rax, [rbp-0x8]
            0x00400593    4883c004     add rax, 0x4
            0x00400597    c6006f       mov byte [rax], 0x6f ;  0x0000006f  -> o
            0x0040059a    488b45f8     mov rax, [rbp-0x8]
            0x0040059e    4883c005     add rax, 0x5
            0x004005a2    c60077       mov byte [rax], 0x77 ;  0x00000077  -> w
            0x004005a5    488b45f8     mov rax, [rbp-0x8]
            0x004005a9    4883c006     add rax, 0x6
            0x004005ad    c6006f       mov byte [rax], 0x6f ;  0x0000006f  -> o
            0x004005b0    488b45f8     mov rax, [rbp-0x8]
            0x004005b4    4883c007     add rax, 0x7
            0x004005b8    c60072       mov byte [rax], 0x72 ;  0x00000072  -> r
            0x004005bb    488b45f8     mov rax, [rbp-0x8]
            0x004005bf    4883c008     add rax, 0x8
            0x004005c3    c6006c       mov byte [rax], 0x6c ;  0x0000006c  -> l
            0x004005c6    488b45f8     mov rax, [rbp-0x8]
            0x004005ca    4883c009     add rax, 0x9
            0x004005ce    c60064       mov byte [rax], 0x64 ;  0x00000064  -> d
            0x004005d1    488b45f8     mov rax, [rbp-0x8]
*/

   write(1, blah, 11);

   write(1, "\n", 1);

   return 0;


}
