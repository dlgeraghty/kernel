bits		32
section		.text
	align		4
	dd		0x1BADB002
	dd		0x00
	dd		- (0x1BADB002+0x00)

global start
extern kmain 		;this function is going to be located on our c code (kernel.c)
start:
	cli		;clears the interrupts
	call kmain	;send processor to continue execution from the kmain function in c code
	; we should never return
.idle:
	hlt		;halt the cpu(pause it from executing from this address)
	jmp .idle
