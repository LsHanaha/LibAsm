


             global         ft_list_size

ft_list_size:                                   ; start pointer in rdi
               mov          rax, 0              ; init rax
               cmp          rdi, 0              ; check pointer not NULL
               je           exit

count:
               inc          rax
               mov          rdi, [rdi + 8]      ; go to nex chain
               cmp          rdi, 0              ; check it's not null
               je           exit
               jmp          count

exit:
               ret