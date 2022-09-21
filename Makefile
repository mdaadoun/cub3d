
NAME = cub3D
SRCS = main.c
DIR = src
OBJS = $(addprefix $(DIR)/cub_,$(SRCS:%.c=%.o))
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror

R = \033[38;5;1m
G = \033[38;5;2m
B = \033[38;5;4m
D = \033[38;5;255m

.c.o:
	@$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(B)Building $(NAME) program.$(D)"
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(G)$(NAME) program created.$(D)"

clean:
	@echo "$(R)Remove all object files.$(D)"
	$(RM) $(OBJS)

fclean: clean
	@echo "$(R)Remove $(NAME) program if present.$(D)"
	$(RM) $(NAME)

re: fclean all

.PHONY:  all clean fclean re