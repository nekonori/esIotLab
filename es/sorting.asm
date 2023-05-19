mov r0,#3Fh
mov r1,#45h
loop: inc r1
inc r0
mov a,r1
mov @r0,a
cjne r0,#44h,loop
; numbers are loaded from 40h to 44h


oloop: mov r3,#04h
mov r0,#40h
mov r1,#41h
mov r2,#04h
iloop: mov a,@r0
subb a,@r1
;jnc for descending
;jc for ascending
jnc noswap
mov a,@r0
mov b,@r1
mov @r1,a
mov a,b
mov @r0,a
noswap: inc r0
inc r1
djnz r3,iloop
djnz r2,oloop