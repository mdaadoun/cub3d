ARG = maps/error/map_error_duplicate.cub

NAME = cub3D
SRCS = main.c file.c free.c errors.c utils.c events.c config.c map.c \
check_map.c colors.c draw.c rays.c\
player.c img.c render.c
DIR = src
OBJS = $(addprefix $(DIR)/cub_,$(SRCS:%.c=%.o))
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror -g
VARG = --track-origins=yes --leak-check=full --show-leak-kinds=all -s

LIBXFLAG = -lXext -lX11
LIBFT = libft/libft.a
LIBXPATH = mlibx/
LIBXNAME = mlibx/libmlx.a

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
	@$(CC) $(FLAGS) $(OBJS) ${LIBFT} ${LIBXNAME} ${LIBXFLAG} -o $(NAME) -lm
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

valgrind:
	valgrind ${VARG} ./${NAME} ${ARG}

run:
	./${NAME} ${ARG}

.PHONY:  all clean fclean re valgrind run
