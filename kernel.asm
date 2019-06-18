bits		32
section		.text
	align		4
	dd		0x1BADB002
	dd		0x00
	dd		- (0x1BADB002+0x00)

global start
global createfile
extern kmain 		;this function is going to be located on our c code (kernel.c)
start:
	cli		;clears the interrupts
	call kmain	;send processor to continue execution from the kmain function in c code
	; we should never return
.idle:
	hlt		;halt the cpu(pause it from executing from this address)
	jmp .idle

createfile:
	 ;create the file
   mov  eax, 8
   mov  ebx, file_name
   mov  ecx, 0777        ;read, write and execute by all
   int  0x80             ;call kernel

   mov [fd_out], eax
	 ret

section .data
file_name db "ola.txt"

section .bss
fd_out resb 1
