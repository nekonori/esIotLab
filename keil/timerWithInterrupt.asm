org 0h
main:
	mov p1, #00h
	call inter
timer:
	mov tmod, #01h
	mov th0, #04h
	mov tl0, #04h
	setb tr0
	jnb tf0, $
	clr tf0
	ret
inter:
	jnb ie.0, $
	setb p1.0
	call timer
	clr p1.0
	call timer
	jmp inter
end