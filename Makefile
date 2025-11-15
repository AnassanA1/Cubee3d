NAME = cube3d.bin



CC = cc
CFLAGS = -Wall -Werror -Wextra -pedantic
CSTAGE = -c

MAIN = src/main.c
INCLUDE = include/main.h

SRC = 



OBJS = $(MAIN:.c=.o) $(SRC:.c=.o)


%.o : %.c $(INCLUDE)
	@echo "compile " $<
	@$(CC) $(CFLAGS) $(CSTAGE) $< -o $@

all : $(NAME)



$(NAME): $(OBJS)
	@echo "linking" $^
	@$(CC) $(CFLAGS) $^ -o $@



re : fclean all


RM = rm
RMFLAGS = -fr


clean :
	@echo "Remove" $(OBJS)
	@$(RM) $(RMFLAGS) $(OBJS)


fclean : clean
	@echo "Remove" $(NAME)
	@$(RM) $(RMFLAGS) $(NAME)



PARAM = # // TODO: Add program params for testing !

run : $(NAME)
	@echo "Running" $(NAME)
	@./$(NAME) $(PARAM)

.PHONY: all clean fclean re run



