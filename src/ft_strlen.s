

        global      ft_strlen
        section     .text

ft_strlen:
        mov         rax, 0                  ; init len

count:
        cmp         BYTE [rdi + rax], 0     ; string is not end
        je          exit                    ; if it ends, return
        inc         rax                     ; else increace len
        jmp         count                   ; goto count again

exit:
        ret

