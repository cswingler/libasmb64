;
; libasmb64_64.s
; --
; http://monobeard.github.com/
;

section .data
  b64table    db    'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/'

section .text
  global b64decode

  ;
  ; __uint64 b64decode(char *in, char *out)
  ;

  b64decode:
    push rbp
    mov  rbp, rsp

    mov  r8, rdi
    mov  r9, rsi
    mov  r10, rsi

    xor  rax, rax
    xor  rcx, rcx
    xor  rdx, rdx
    xor  r11, r11

    _loop:
      mov  al, [r8]
      test al, al
      jz   _exit
      mov  cl, 64
      mov  rdi, b64table
      repnz scasb
      test cl, cl
      je   _increment
      not  cl
      add  cl, 64
      shl  r11, 6
      or   r11, rcx
      add  ah, 6
      cmp  ah, 8
      jb   _increment
      sub  ah, 8
      mov  cl, ah
      mov  rdx, r11
      shr  rdx, cl
      mov  [r9], dl
      inc  r9

    _increment:
      inc  r8
      jmp  _loop

    _exit:
      mov  rax, r9
      sub  rax, r10
      mov  rsp, rbp
      pop  rbp
      ret


