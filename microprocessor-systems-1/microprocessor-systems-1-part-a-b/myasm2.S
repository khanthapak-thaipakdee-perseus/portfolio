    AREA asm_func, CODE, READONLY
    
; Export my asm function location so that C compiler can find it and link
    EXPORT simple_sqrt
    
    ALIGN
 
simple_sqrt FUNCTION
    ; Input : R0
    ; Output : R0 (square root result)
    MOVW R1, #0x8000 ; R1 = 0x00008000
    MOVS R2, #0 ; Initialize result
simple_sqrt_loop
    ADDS R2, R2, R1 ; M = (M + N)
    MUL R3, R2, R2 ; R3 = M^2
    CMP R3, R0 ; If M^2 > Input
    IT HI ; Greater Than
    SUBHI R2, R2, R1 ; M = (M - N)
    LSRS R1, R1, #1 ; N = N >> 1
    BNE simple_sqrt_loop
    MOV R0, R2 ; Copy to R0 and return
    BX LR ; Return
ENDFUNC
