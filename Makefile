.SILENT:

SRC	= main.c \
	basic_fun.c \
	mandatory_utils.c \

SRC_BONUS = main_bonus.c \
	flag_dot/dot_case.c \
	flag_dot/handle_dot_case.c \
	flag_dot/dot_uns_case.c \
	flag_dot/spec_dot_case.c \
	flag_dot/spec_dot_neg_case.c \
	\
	flag_pos/handle_pos.c \
	flag_pos/pos_num_case.c \
	flag_pos/pos_case.c \
	flag_pos/pos_num_case.c \
	flag_pos/neg_pos_case.c \
	flag_pos/neg_pos_num_case.c \
	\
	flag_space/handle_space.c \
	flag_space/space_num_utils.c \
	flag_space/space_utils.c \
	\
	flag_width/handle_width.c \
	flag_width/neg_width_num_utils.c \
	flag_width/neg_width_utils.c \
	flag_width/width_num_utils.c \
	flag_width/width_utils.c \
	\
	flag_zero/handle_zero.c \
	flag_zero/neg_zero_addr.c \
	flag_zero/neg_zero_num.c \
	flag_zero/zero_addr.c \
	flag_zero/zero_num.c \
	\
	basic_fun_bonus.c \
	bonus_utils.c \
	handle_sharp.c \
	mandatory_utils_bonus.c \

OBJS = $(addprefix mandatory/, $(notdir $(SRC:.c=.o)))

OBJS_BONUS = $(addprefix bonus/, $(SRC_BONUS:.c=.o))

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

bonus: $(OBJS_BONUS) $(LIBFT)
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
