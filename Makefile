NAME = cube3D



CC = cc
CFLAGS = -Wall -Werror -Wextra -pedantic
CSTAGE = -c

MAIN = src/main.c
INCLUDE = include/main.h

DEPENDENCY_PATH = libs/libft
DEPENDENCY = $(DEPENDENCY_PATH)/libft.a
DEPENDENCY_NAME = ft
DEPENDENCY_HEADER = $(DEPENDENCY_PATH)

FRAMEWORKS = -framework OpenGL -framework AppKit
MLXLIB = -lmlx $(FRAMEWORKS)

SRCS =	src/utils/game_init.c \
		src/utils/game_destroy.c \
		src/utils/error/error_handler.c \
		src/utils/error/error_helpers.c \
		src/utils/input/input_handler.c \
		src/utils/input/input_validator.c \
		src/utils/map/map_handler.c \
		src/utils/map/read_raw_map.c \
		src/utils/map/isMapConfig.c \
		src/utils/texture/texture_handler.c \
		src/utils/texture/handler_east.c \
		src/utils/texture/handler_floor.c \
		src/utils/texture/handler_north.c \
		src/utils/texture/handler_sky.c \
		src/utils/texture/handler_south.c \
		src/utils/texture/handler_west.c \
		src/utils/texture/texture_format_handler.c \
		src/utils/allGood.c \
		src/utils/concat3.c \
		src/utils/find_replace.c \
		src/utils/is_space.c

TEST =	src/test/test.c
OBJS = $(MAIN:.c=.o) $(SRCS:.c=.o) $(TEST:.c=.o)


%.o : %.c $(INCLUDE)
	@echo $(COLMPILE) $<
	@$(CC) $(CFLAGS) $(CSTAGE) $< -o $@

all : $(NAME)



$(NAME): $(DEPENDENCY)  $(OBJS) 
	@echo $(LINK) $^
	@$(CC) $(CFLAGS) -L$(DEPENDENCY_PATH) -l$(DEPENDENCY_NAME) -I$(DEPENDENCY_HEADER) $(MLXLIB) $^ -o $@
	@echo $(BULILD_MESSAGE)

$(DEPENDENCY):
	@echo $(BUILD) $@
	@make -C $(DEPENDENCY_PATH) --no-print-directory
	@echo $(DEPENDENCY_MESSAGE)


re : fclean all


RM = rm
RMFLAGS = -fr


clean :
	@echo $(REMOVE) $(OBJS)
	@$(RM) $(RMFLAGS) $(OBJS)
	@make -C $(DEPENDENCY_PATH) clean --no-print-directory


fclean : clean
	@echo $(REMOVE) $(DEPENDENCY)
	@$(RM) $(RMFLAGS) $(DEPENDENCY)
	@echo $(REMOVE) $(NAME)
	@$(RM) $(RMFLAGS) $(NAME)


# // TODO: Add program params for testing !

PARAM = txt.cube

run : fclean $(NAME)
	@echo $(RUNNING) $(NAME)
	@./$(NAME) $(PARAM)

.PHONY: all clean fclean re run


# MESSAGES 

DEPENDENCY_MESSAGE = "\033[1;32m--------------- ✨libft was built successfuly✨ ---------------\033[0m"
BULILD_MESSAGE = "\033[1;32m--------------- ✨cube3D was built successfuly✨ ---------------\033[0m"
COLMPILE = "\033[1;33m🛠️ Compile :\033[0m"
LINK = "\033[1;34m🔗 Link : \033[0m"
REMOVE = "\033[1;90m🗑️  Remove :\033[0m"
BUILD = "\033[1;35m🛠️ Building :\033[0m"
RUNNING = "\033[1;35m🚀 Running :\033[0m"



# NORMS CHECK AND STYLING !

ESC := $(shell printf '\033')
RED := $(ESC)[1;31m
GREEN := $(ESC)[1;32m
RESET := $(ESC)[0m

ERRORNORM := $(RED)💀 Error:$(RESET)
OKNORM := $(GREEN)✅ Valid: $(RESET)
GOODNORM := $(GREEN)--------------- ✅ GOOD NORMS ✅ --------------- $(RESET)
BADNORM := $(RED)--------------- 💀 BAD NORMS 💀 ---------------$(RESET)

normscheck:
	@errors=$$(norminette | grep "Error"); \
	if [ -n "$$errors" ]; then \
		echo "$(BADNORM)"; \
		echo "$$errors" | sed "s/Error:/$(ERRORNORM)/g"; \
	else \
		echo "$(GOODNORM)"; \
		norminette | tr -d ":OK!" | sed "s/^/$(OKNORM)/g"; \
	fi