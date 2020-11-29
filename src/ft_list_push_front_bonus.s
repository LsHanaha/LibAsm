

            global          ft_list_push_front
            extern          malloc


ft_list_push_front:

            cmp             rdi, 0
            je              exit_error

allocate:
            mov             r15, rdi            ; because of malloc
            mov             r14, rsi            ; because of malloc

            mov             rdi, 16             ; size_of t_list
            call            malloc WRT ..plt
            cmp             rax, 0
            jl              exit_error
            mov             rdi, r15            ; restore values
            mov             rsi, r14            ; restore values

push_front:
            mov             [rax], rsi      ; mov data to data in structure
            mov             rbx, [rdi]          ; store current start in buffer
            mov             [rax + 8], rbx      ; store current start in nex field of new chain
            mov             [rdi], rax          ; rewrite value of current start
            ret

exit_error:
            mov             rax, 0
            ret

