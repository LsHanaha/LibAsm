

        global      ft_read
        extern      __errno_location                ; too many problems with ___error in linux :(

        section     .text

ft_read:
		mov	        rax, 0                          ; call write
		syscall
		cmp         rax, 0                          ; if error it returns in rax as neg value
		jl          exit_error
		ret


exit_error:
        neg         rax                             ; make errno positive
        mov         r15, rax                        ; save errno
        call        __errno_location WRT  ..plt     ; initialize errno, prepare pointer in rax
        mov         [rax], r15                      ; store value by this pointer
        mov         rax, -1                         ; common write error res
        ret
