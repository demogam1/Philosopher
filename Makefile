NAME = philo.a

PROGRAM_NAME = philo

FLAGS = -Wall -Wextra -Werror 

CC = gcc -g -pthread

AR = ar -rcs

DELETE = rm -f

SRC = 	philo.c \
		utils.c \
		ft_time.c \
		norm_extension.c \
		norm_extension_1.c \

O_FILE = $(SRC:.c=.o)

%.o : %.c
	@printf "\x1b[33m \x1b[1m Converting \x1b[0m  \x1b[36m $< \x1b[0m \x1b[33m \x1b[1m to \x1b[0m \x1b[34m $@ \x1b[0m \r"	
	@printf "\x1b[32m    [DONE]      \x1b[0m"
	@$(CC) $(FLAGS) -c $< -o $@


$(NAME) : $(O_FILE)
	@$(AR) $(NAME) $(O_FILE) 
	@$(CC) $(FLAGS) $(NAME) -o $(PROGRAM_NAME) $?

all : $(NAME)

clean:
	@echo "\x1b[1m \x1b[31m [CLEAN] : \x1b[0m \x1b[33m \x1b[1m $(O_FILE) \x1b[0m \n " 
	@$(DELETE) $(O_FILE)

fclean: clean
	@echo "\x1b[1m \x1b[31m [FCLEAN] : \x1b[0m \x1b[33m \x1b[1m $(NAME) | $(PROGRAM_NAME) \x1b[0m \n "
	@$(DELETE) $(NAME) $(PROGRAM_NAME)

re: fclean all