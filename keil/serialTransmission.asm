org 0h
mov scon, #40h
mov tmod, #20h
mov th1, #-3
mov tl1, #-3
setb tr1
setb tr1
repeat:
 mov sbuf, #"Y"
 acall tran
 mov sbuf, #"E"
 acall tran
 mov sbuf, #"S"
 acall tran
 sjmp repeat
tran:
 jnb ti, $
 clr ti
 ret
end