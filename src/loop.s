.intel_syntax

.globl _myloop

.text

_myloop:
      mov eax, 10
      
_begin:
      dec eax
      jz _begin
      #jnz _begin
      ret
