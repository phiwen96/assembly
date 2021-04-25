.intel_syntax

.globl _passing_three_parameters
.text
_passing_three_parameters:
      mov rax, rdi
      add rax, rsi
      add rax, rdx
      ret
