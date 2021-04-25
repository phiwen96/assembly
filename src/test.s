.intel_syntax
.globl _someFunction

.text
_someFunction:
      mov rax, 123
      inc rax
      sub rax, 1
      jmp MyLabel
      dec rax
      ret

MyLabel:
      ret


message:
      .ascii "hello\12\0"
