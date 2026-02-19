NAME = cube3D



CC = cc
CFLAGS = -Wall -Werror -Wextra 
CSTAGE = -c
#CFLAGS += -pedantic -fsanitize=address -g

MAIN = main.c
INCLUDE = include/main.h include/const.h include/typedef.h include/error.h

DEPENDENCY_PATH = libs/libft
DEPENDENCY = $(DEPENDENCY_PATH)/libft.a
DEPENDENCY_NAME = ft
DEPENDENCY_HEADER = $(DEPENDENCY_PATH)

#FRAMEWORKS = -ldl -lglfw -pthread -lm
FRAMEWORKS = -framework OpenGL -framework AppKit -L/Users/msidry/.brew/lib -lglfw
MLXLIB_NAME = mlx42
MLXLIB = -l$(MLXLIB_NAME) $(FRAMEWORKS)
MLXLIB_DIR = libs/mlx/

SRCS =	src/utils/game_init.c \
		src/utils/game_destroy.c \
		src/utils/input/input_validator.c \
		src/utils/config/read_raw_config.c \
		src/utils/config/split_raw_config.c \
        src/utils/config/valid_textures.c \
		src/utils/config/valid_texture_image.c \
        src/utils/config/valid_texture_solid.c \
		src/utils/map/map_handler.c \
		src/utils/map/map_validator.c \
		src/utils/map/map_validations.c  \
		src/utils/mlx/mlx_handler.c \
		src/utils/texture/textures_handler.c \
		src/utils/texture/load_texture_image.c \
		src/utils/texture/get_color.c \
		src/utils/game_run.c \
		src/utils/game_loop.c \
		src/utils/movements/handler.c \
		src/utils/movements/move.c \
		src/utils/movements/rotate.c \
		src/utils/drawing/drawing.c \
		src/utils/raycasting/raycasting.c \
		src/utils/raycasting/dda.c

		
		

HELPERS =	src/utils/help/get_next_line.c \
			src/utils/help/array2d.c \
			src/utils/help/concat3.c \
			src/utils/help/contain_only.c \
			src/utils/help/converter.c \
			src/utils/help/find_replace.c \
			src/utils/help/is_space.c \
			src/utils/help/match_count.c \
			src/utils/help/capitalize.c \
			src/utils/help/serialize.c \
			src/utils/help/transform.c \
			src/utils/help/ft_realloc.c \
			src/utils/help/normalize.c \
			src/utils/help/boundaryfloodfill.c \
			src/utils/queue/q_crud.c \
			src/utils/queue/q_find.c  \
			src/utils/queue/q_last.c  \
			src/utils/queue/q_pop.c \
			src/utils/queue/q_push.c

		 

OBJS = $(MAIN:.c=.o) $(SRCS:.c=.o) $(HELPERS:.c=.o)


%.o : %.c $(INCLUDE)
	@echo $(COLMPILE) $<
	@$(CC) $(CFLAGS) $(CSTAGE) $< -o $@

all : $(NAME)



$(NAME): $(DEPENDENCY)  $(OBJS) 
	@echo $(LINK) $^
	@$(CC) $(CFLAGS) $^ -L$(DEPENDENCY_PATH) -l$(DEPENDENCY_NAME) -I$(DEPENDENCY_HEADER) -L$(MLXLIB_DIR) -I$(MLXLIB_DIR) $(MLXLIB)  -o $@
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

PARAM = test.cub

run : $(NAME)
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