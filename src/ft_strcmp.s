

        global      ft_strcmp
        section     .text


ft_strcmp:
        mov         r8, 0                   ; initialize on of the scratch reg

comparison:
        mov         al, byte [rdi + r8]     ; copy char in reg
        mov         bl, byte [rsi + r8]
        cmp         al, bl                  ; compare 2 chars
        jne         not_equal

        cmp         al, 0                   ; if equal and 0, goto the exit
        je          equal

        inc         r8
        jmp         comparison


not_equal:
        jl          less                    ; flag from 13s row is still active, use it
        mov         rax, 1
        ret

less:
        mov         rax, -1
        ret

equal:
        mov         rax, 0
        ret