
        global      ft_strdup
        section     .text
        extern      malloc


ft_strdup:
        mov         rcx, 0                  ; arg strings len is 0
        mov         r14, rdi                ; copy init str pointer to r14
        xor         rax, rax                ; make shure rax is 0


str_len:
        cmp         BYTE [rdi + rcx], 0     ; string is not end
        je          allocate                ; if it ends, return
        inc         rcx                     ; else increace len
        jmp         str_len                 ; goto count again


allocate:
        inc         rcx                     ; why not)
        mov         rdi, rcx                ; store length of init str in rdi for calling malloc
        call        malloc WRT ..plt
        cmp         rax, 0                  ; if not memory, go to error
        jl          exit_error

        mov         rdi, r14                ; restore init str in rdi
        mov         r14, 0                  ; clear r14


copy:
        cmp         BYTE [rdi + r14], 0     ; src string is not over?
        je          exit                    ; oh, it is

        mov         r13, [rdi + r14]        ; else write byte to the dest
        mov         [rax + r14], r13        ; using buffer
        inc         r14                     ; inc index
        jmp         copy                    ; goto copy


exit:
        ret


exit_error:
        mov         rax, 0
        ret
