NAME = 		libasm.a

SRC_DIR	=	./src/

MAN_SRC = 	ft_strlen.o \
			ft_strcpy.o \
			ft_strcmp.o \
			ft_write.o \
			ft_read.o \
			ft_strdup.o

BON_SRC =	ft_atoi_base_bonus.o \
			ft_list_push_front_bonus.o \
			ft_list_size_bonus.o \
			ft_list_sort_bonus.o \
			ft_list_remove_if_bonus.o

MAN_SRC :=		$(MAN_SRC:%=$(SRC_DIR)%)

BON_SRC :=		$(BON_SRC:%=$(SRC_DIR)%)

ifdef WITH_BONUS
SRC_FILES = $(MAN_SRC) $(BON_SRC)
else
SRC_FILES = $(MAN_SRC)
endif


all: $(NAME)

$(NAME): $(SRC_FILES)
	ar rcs $(NAME) $(SRC_FILES)

%.o: %.s
	nasm -felf64 -o $@ $<

bonus:
	$(MAKE) WITH_BONUS=1 all

test_bonus: fclean bonus
	clang $(FLAGS) tests/test_bonus.c -L. -lasm -o test_bonus

test: re
	clang $(FLAGS) tests/test.c -L. -lasm -o test

clean:
	rm -rf $(MAN_SRC) $(BON_SRC)

fclean: clean
	rm -rf $(NAME) test test_bonus

re:	fclean all