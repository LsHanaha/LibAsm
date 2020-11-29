

        global      ft_strcpy
        section     .text


ft_strcpy:
        mov         rax, 0                  ;init start index


copy:
        cmp         BYTE [rsi + rax], 0     ; src string is not over?
        je          exit                    ; oh, it is

        mov         ecx, [rsi + rax]        ; else write byte to the dest
        mov         [rdi + rax], ecx        ; using buffer
        inc         rax                     ; inc index
        jmp         copy                    ; goto copy


exit:
        mov         BYTE [rdi + rax], 0     ; add string-terminated 0
        xor         rax, rax                ; clear rax, why?
        mov         rax, rdi                ; retrun rdi
        ret