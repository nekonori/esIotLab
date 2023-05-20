MOVR0,#20H; Initialize the address of the data
MOVA,@R0; Get the data from an address, which is stored in R0
MOVR2,A;Store the content of A into R2
CLRC; Clear the Carry Flag
SUBBA,#0AH;Subtract 0AH from A
JCNUM ; When a carry is present, A is numeric
ADDA,#41H;Add41H for Alphabet
SJMPSTORE; Jump to store the value
NUM:    MOVA,R2; Copy R2 to A
ADDA,#30H; Add 30H with A to get ASCII
STORE:  MOVR0,#30H; Point the destination location
MOV@R0,A; Store A content to the memory location pointed by R0
HALT:   SJMPHALT
