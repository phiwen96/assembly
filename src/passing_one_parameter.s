.intel_syntax
.globl _passing_one_parameter

.text 
_passing_one_parameter:
    mov rax, rdi
    dec rax
    ret
