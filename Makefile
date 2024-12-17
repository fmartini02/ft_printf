.SILENT:

SRC	= main.c \
	basic_fun.c \
	mandatory_utils.c \

SRC_BONUS = main_bonus.c \
	mandatory_utils_bonus.c \
	basic_fun_bonus.c \
	handle_spec.c \
	handle_space.c \
	handle_num.c \
	num_utils.c \
	neg_num_utils.c \
	dot_case.c \
	dot_uns_case.c \
	zero_case.c \
	bonus_utils.c \

OBJS = $(addprefix mandatory/, $(notdir $(SRC:.c=.o)))

OBJS_BONUS = $(addprefix bonus/, $(notdir $(SRC_BONUS:.c=.o)))

NAME = libftprintf.a

CC = clang

RM = rm -f

LIBFT = libft/libft.a

FLAGS = -Werror -Wall -Wextra -g

EXE = exe

MAKE := make --no-print-directory

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft
	$(MAKE) -C libft bonus

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

bonus : $(OBJS_BONUS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJS_BONUS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)
	$(MAKE) -C libft clean

fclean:	clean
	$(RM) $(NAME) $(EXE)
	$(MAKE) -C libft fclean

re:	fclean all

$(EXE):	re
	$(CC) $(FLAGS) -o exe $(OBJS) $(NAME)
	$(MAKE) clean

.PHONY:	all clean fclean re exe bonus
