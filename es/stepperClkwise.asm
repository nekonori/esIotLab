9100:
MOV R2,#FF
DLY1: MOV R3,#0A
DLY2: DJNZ R3,DLY2
DJNZ R2,DLY1
RET

9000:
MOV DPTR,#6003
MOV A,#80H
MOVX @DPTR,A
MOV DPTR,#6000

LOOP:
MOV A,#04H
MOVX @DPTR,A
LCALL DELAY

MOV A,#06H
MOVX @DPTR,A
LCALL DELAY

MOV A,#07H
MOVX @DPTR,A
LCALL DELAY

MOV A,#05H
MOVX @DPTR,A
LCALL DELAY

SJMP LOOP