org 0h
mov scon, #50h
mov p0, #00h
mov tmod, #20h
mov th1,#-3
mov tl1,#-3
setb tr1
here:
 jnb ri, $
 mov a, sbuf
 mov p0, a
 clr ri
 sjmp here
end