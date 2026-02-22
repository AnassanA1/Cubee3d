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
FRAMEWORK_PATH = /Users/azghibat/homebrew/lib
FRAMEWORKS = -framework OpenGL -framework AppKit -L $(FRAMEWORK_PATH) -lglfw
MLXLIB_NAME = mlx42
MLXLIB = -l$(MLXLIB_NAME) $(FRAMEWORKS)
MLXLIB_DIR = libs/mlx/

SRCS =	src/game_init.c \
		src/game_destroy.c \
		src/input/input_validator.c \
		src/config/read_raw_config.c \
		src/config/split_raw_config.c \
        src/config/valid_textures.c \
		src/config/valid_texture_image.c \
        src/config/valid_texture_solid.c \
		src/map/map_handler.c \
		src/map/map_validator.c \
		src/map/map_validations.c  \
		src/mlx/mlx_handler.c \
		src/texture/textures_handler.c \
		src/texture/load_texture_image.c \
		src/texture/get_color.c \
		src/game_run.c \
		src/game_loop.c \
		src/movements/handler.c \
		src/movements/move.c \
		src/movements/rotate.c \
		src/drawing/pixels.c \
		src/drawing/drawing.c \
		src/raycasting/raycasting.c \
		src/raycasting/dda.c

		
		

HELPERS =	src/help/get_next_line.c \
			src/help/array2d.c \
			src/help/concat3.c \
			src/help/contain_only.c \
			src/help/converter.c \
			src/help/find_replace.c \
			src/help/is_space.c \
			src/help/match_count.c \
			src/help/capitalize.c \
			src/help/serialize.c \
			src/help/transform.c \
			src/help/ft_realloc.c \
			src/help/normalize.c \
			src/help/boundaryfloodfill.c \
			src/help/min_max.c \
			src/queue/q_crud.c \
			src/queue/q_find.c  \
			src/queue/q_last.c  \
			src/queue/q_pop.c \
			src/queue/q_push.c \

		 

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


TESTMAP = maps/test.cub

run : $(NAME)
	@echo $(RUNNING) $(NAME)
	@./$(NAME) $(TESTMAP)
	@echo $(EXITING) $(NAME)

.PHONY: all clean fclean re run mlx_setup



MLX_DIR = /tmp/MLX42
MLX_BUILD = $(MLX_DIR)/build
MLX_LOCAL = libs/mlx

mlx_setup:
	@if [ ! -d "$(MLX_DIR)" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git $(MLX_DIR); \
	fi
	cmake -S $(MLX_DIR) -B $(MLX_BUILD)
	cmake --build $(MLX_BUILD)
	mkdir -p $(MLX_LOCAL)
	cp $(MLX_BUILD)/libmlx42.a $(MLX_LOCAL)
	cp -r $(MLX_DIR)/include/MLX42/ $(MLX_LOCAL)




# MESSAGES 

DEPENDENCY_MESSAGE = "\033[1;32m--------------- ✨libft was built successfuly✨ ---------------\033[0m"
BULILD_MESSAGE = "\033[1;32m--------------- ✨cube3D was built successfuly✨ ---------------\033[0m"
COLMPILE = "\033[1;33m🛠️ Compile :\033[0m"
LINK = "\033[1;34m🔗 Link : \033[0m"
REMOVE = "\033[1;90m🗑️  Remove :\033[0m"
BUILD = "\033[1;35m🛠️ Building :\033[0m"
RUNNING = "\033[1;35m🚀 Running :\033[0m"

EXITING = "\033[1;35m🚀 exiting :\033[0m"

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
