NAME = cub3D
SRCS = main.c file.c free.c errors.c utils.c events.c config.c map.c check_map.c
DIR = src
OBJS = $(addprefix $(DIR)/cub_,$(SRCS:%.c=%.o))
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror

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
	@$(CC) $(FLAGS) $(OBJS) debug/debug.c ${LIBFT} ${LIBXNAME} ${LIBXFLAG} -o $(NAME) #REMOVE DEBUG
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

DFLAGS = -g3 -ggdb -I. -D DEBUG=1
DSRCS = debug/debug.c src/cub_main.c src/cub_file.c src/cub_free.c \
src/cub_config.c src/cub_utils.c src/cub_errors.c src/cub_events.c \
src/cub_map.c src/cub_check_map.c
VARG = --track-origins=yes --leak-check=full --show-leak-kinds=all -s
ARG = maps/map_basic_1.cub

debug: fclean
	@make -sC libft
	@make -sC ${LIBXPATH}
	@echo "$(B)Building $(NAME) debug program.$(D)"
	@$(CC) $(FLAGS) $(DFLAGS) ${DSRCS} ${LIBFT} ${LIBXNAME} ${LIBXFLAG} -o $(NAME)
	@echo "$(G)$(NAME) debug program created.$(D)"

valgrind:
	valgrind ${VARG} ./${NAME} ${ARG}

run:
	./${NAME} ${ARG}

.PHONY:  all clean fclean re debug valgrind run
