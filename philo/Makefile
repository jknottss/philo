NAME = philo

SRC = init_func.c main.c monitor_func.c philo_func.c \
	  utils.c

OBJS = ${SRC:%.c=%.o}

CC = cc -Wall -Werror -Wextra

RM = rm -f

%.o:		%.c philo.h
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