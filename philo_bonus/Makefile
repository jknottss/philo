NAME = philo_bonus

SRC = init_func_bonus.c main_bonus.c monitor_func_bonus.c \
	  philo_func_bonus.c utils_bonus.c utils_2_bonus.c

OBJS = ${SRC:%.c=%.o}

CC = cc -Wall -Werror -Wextra

RM = rm -f

%.o:		%.c philo_bonus.h
			$(CC) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC)  $(OBJS) -o $(NAME)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re: 		fclean all

.PHONY: clean fclean re all