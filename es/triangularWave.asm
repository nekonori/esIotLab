8500:
MOV A,#80
MOV DPTR,#6003
MOVX @DPTR,A
MOV DPTR,#6001
8509:
MOV A,#00
850B:
MOVX @DPTR,A
ADD A,#01
CJNE A,#FF,850B
8511:
SUBB A,#01
MOVX @DPTR,A
CJNE A,#00,8511
SJMP 8509