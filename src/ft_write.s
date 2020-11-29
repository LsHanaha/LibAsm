

        global      ft_write
        extern      __errno_location                ; too many problems with ___error in linux :(

        section     .text

ft_write:                                           ; syscall have to have rdi - fd, rsi - text pointer and rdx - count
                                                    ; we have it all from main.c
		mov	        rax, 1                          ; call write
		syscall
		cmp         rax, 0                          ; if error it returns in rax as neg value
		jl	        exit_error
		ret                                         ; else in rax stores count of printed chars


exit_error:
        neg         rax                             ; make errno positive
        mov         r15, rax                        ; save errno
        call        __errno_location WRT  ..plt     ; initialize errno, prepare pointer in rax
        mov         [rax], r15                      ; store value by this pointer
        mov         rax, -1                         ; common write error res
        ret
