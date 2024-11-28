.SILENT:

SRC	= main.c utils.c basic_fun.c

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
