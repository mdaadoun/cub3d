
ARG = maps/map_basic.cub
NAME = cub3D
SRCS = main.c exit.c data_set.c free.c errors.c
DIR = src
OBJS = $(addprefix $(DIR)/cub_,$(SRCS:%.c=%.o))
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror # -g
LIBXFLAG = -lXext -lX11
LIBFT = libft/libft.a
LIBXPATH = ./mlbx/minilibx-linux/
LIBXNAME = $(addprefix $(LIBXPATH)libmlx.a,)

R = \033[38;5;1m
G = \033[38;5;2m
B = \033[38;5;4m
D = \033[38;5;255m

.c.o:
	@$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	@make -sC libft
	@make -sC ${LIBXPATH}
	@echo "$(B)Building $(NAME) program.$(D)"
	@$(CC) $(FLAGS) $(OBJS) ${LIBFT} ${LIBXNAME} ${LIBXFLAG} -o $(NAME)
	@echo "$(G)$(NAME) program created.$(D)"

clean:
	@echo "$(R)Remove all object files.$(D)"
	@$(RM) $(OBJS)
	@make clean -sC libft

fclean: clean
	@echo "$(R)Remove $(NAME) program if present.$(D)"
	@$(RM) $(NAME)
	@make fclean -sC libft
	@make clean -sC ${LIBXPATH}

re: fclean all

D_FLAGS = -g3 -ggdb -I. -D DEBUG=1
D_DIR = debug
D_SRCS = debug.c
D_OBJS = $(addprefix $(D_DIR)/,$(D_SRCS:%.c=%.o))
V_ARG = --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s

debug: $(OBJS) ${D_OBJS}
	@make -sC libft
	@echo "$(B)Building $(NAME) debug program.$(D)"
	@$(CC) $(FLAGS) $(D_FLAGS) $(OBJS) ${D_OBJS} ${LIBFT} -o $(NAME)
	@echo "$(G)$(NAME) debug program created.$(D)"

valgrind:
	valgrind ${V_ARG} ./${NAME} ${ARG}

run:
	./${NAME} ${ARG}

.PHONY:  all clean fclean re
