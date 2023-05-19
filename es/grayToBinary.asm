mov r0,#0fh
mov a,r0
mov r3,#07
loop: mov b,a
rrc a
xrl a,b
clr c
djnz r3,loop