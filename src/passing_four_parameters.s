.intel_syntax


.global _passing_four_parameters
.text
_passing_four_parameters:
      mov rax, rdi
      add rax, rsi
      add rax, rdx
      add rax, rcx
      ret


mybyte: .word
