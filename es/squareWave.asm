9000:
MOV A,#80
MOV DPTR,#6003
MOVX @DPTR,A
MOV DPTR,#6001

9009:MOV A,#00
MOVX @DPTR,A
LCALL 9100

MOV A,#33
MOVX @DPTR,A
LCALL 9100
SJMP 9009

9100:
MOV R3,#FF
DJNZ R3,9102
RET