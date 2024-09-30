    AREA asm_func, CODE, READONLY
    THUMB
    
    ; Export my asm function location so that C compiler can find it and link
    EXPORT square_root_fpu
    
square_root_fpu FUNCTION

    ; Enable FPU
    LDR r1, =0xE000ED88

    ; Read CPACR
    LDR r2, [r1]
    ORR r2, r2, #(0xF << 20)
    STR r2, [r1]
    DSB
    ISB

    VMOV s0, r0
    VCVT.F32.U32 s0, s0
    VSQRT.F32 s0, s0
    VCVT.U32.F32 s0, s0
    VMOV r0, s0
    BX LR

    ENDFUNC
    END
