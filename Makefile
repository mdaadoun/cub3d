
ARG = maps/map_basic.cub
NAME = cub3D
SRCS = main.c exit.c data_set.c
D_SRCS = debug.c
DIR = src
OBJS = $(addprefix $(DIR)/cub_,$(SRCS:%.c=%.o))
D_OBJS = $(addprefix $(DIR)/,$(D_SRCS:%.c=%.o))
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror -g
LIBFT = libft/libft.a
V_ARG = --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s

R = \033[38;5;1m
G = \033[38;5;2m
B = \033[38;5;4m
D = \033[38;5;255m

.c.o:
	@$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJS) ${D_OBJS}
	@make -sC libft
	@echo "$(B)Building $(NAME) program.$(D)"
	@$(CC) $(FLAGS) $(OBJS) ${D_OBJS} ${LIBFT} -o $(NAME)
	@echo "$(G)$(NAME) program created.$(D)"

clean:
	@echo "$(R)Remove all object files.$(D)"
	@$(RM) $(OBJS)
	@make clean -sC libft

fclean: clean
	@echo "$(R)Remove $(NAME) program if present.$(D)"
	@$(RM) $(NAME)
	@make fclean -sC libft

re: fclean all

valgrind:
	valgrind ${V_ARG} ./${NAME} ${ARG}

run:
	./${NAME} ${ARG}

.PHONY:  all clean fclean re
