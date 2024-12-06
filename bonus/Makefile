.SILENT:

SRC	= main_bonus.c \
	mandatory_utils_bonus.c \
	basic_fun_bonus.c \
	handle_spec_bonus.c \
	handle_space_bonus.c \
	dot_case_bonus.c \
	zero_case_bonus.c \
	bonus_utils_bonus.c \

OBJS = $(SRC:.c=.o)

NAME = libftprintf.a

CC = cc

RM = rm -f

LIBFT = libft/libft.a

FLAGS = -Werror -Wall -Wextra -g

EXE = exe

%.o:	%.c
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(LIBFT):
	make -C libft
	make -C libft bonus

$(NAME):	$(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

all:	$(NAME)

clean:
	$(RM) $(OBJS)
	make -C libft clean

fclean:	clean
	$(RM) $(NAME) $(EXE)
	make -C libft fclean

re:	fclean all

$(EXE):	re
	$(CC) $(FLAGS) -o exe $(OBJS) $(NAME)
	make clean

repo:	fclean

.PHONY:	all clean fclean re exe repo
