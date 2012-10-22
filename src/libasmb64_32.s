;
; libasmb64_32.s
; --
; http://monobeard.github.com/
;

section .data
  b64table    db    'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/'

section .text
  global b64decode

  ;
  ; __uint32 b64decode(char *in, char *out)
  ;

  b64decode:
    push ebp
    mov  ebp, esp

    push ebx
    push esi
    push edi

    xor  eax, eax
    xor  ebx, ebx
    xor  ecx, ecx
    xor  edx, edx

    lea  ebx, [ebp+0x8]
    mov  ebx, [ebx]

    lea  esi, [ebp+0xc]
    mov  esi, [esi]

    _loop:
      mov  al, [ebx]
      test al, al
      jz    _exit
      mov  cl, 64
      mov  edi, b64table
      repnz scasb
      test cl, cl
      je   _increment
      not  cl
      add  cl, 64
      shl  edx, 6
      or   edx, ecx
      add  ah, 6
      cmp  ah, 8
      jb   _increment
      sub  ah, 8
      mov  cl, ah
      mov  eax, edx
      shr  eax, cl
      mov  ah, cl
      mov  [esi], al
      inc  esi

    _increment:
      inc  ebx
      jmp  _loop

    _exit:
      lea  ecx, [ebp+0xc]
      mov  ecx, [ecx]
      mov  eax, esi
      sub  eax, ecx

      pop  edi
      pop  esi
      pop  ebx

      mov  esp, ebp
      pop  ebp
      
      ret

