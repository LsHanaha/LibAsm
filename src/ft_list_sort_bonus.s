

        global          ft_list_sort

ft_list_sort:                                   ; rdi - list, rsi - function

        cmp             rdi, 0
        je              exit_error
        cmp             rsi, 0
        je              exit_error

        mov             r15, [rdi]
        mov             rdi, [rdi]

loop:
		cmp             rdi, 0
		je              exit
		mov             r9, [rdi + 8]           ; store next elem in reg
		cmp             r9, 0                   ; check not null
		je              exit
		mov             r12, rdi
		mov             r13, rsi
		mov             r14, [rdi + 8]           ; rdi + 8 = next element
		mov             rsi, [r14 + 0]           ; next value to 2nd strcmp arg
		mov             rdi, [rdi + 0]           ; curr value to 1st strcmp arg
		call            r13                      ; call strcmp
		mov             rdi, r12
		mov             rsi, r13
		jns             swap                    ; jump if next larger current
next:
		mov             rdi, [rdi + 8]           ; current element is now next element
		jmp             loop
swap:
		cmp             rax, 0                   ; check calues are equal
		je              next
		mov             r10, [rdi + 0]           ; put current.data in register
		mov             r11, [r14 + 0]           ; put next.data in register
		mov             [r14 + 0], r10           ; swap next.data for current.data
		mov             [rdi + 0], r11           ; swap current.data for next.data
		mov             rdi, r15                 ; reset start pointer in list
		jmp             loop


exit:
        ret


exit_error:
        mov             rax, 0
        ret

