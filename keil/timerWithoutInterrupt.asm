org 0h
mov p0,#0
main:
	setb p0.1
	call timer
	clr p0.1
	call timer
	jmp main
timer:
	mov tmod, #01h
	mov th0, #04h
	mov tl0, #04h
	setb tr0
	wait: jnb tf0, wait	
	clr tf0
	clr tr0
	ret
end