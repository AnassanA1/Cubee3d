NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I./includes -I./MLX42/include
MLXFLAGS = -framework OpenGL -framework AppKit -L/opt/homebrew/lib -lglfw

SRCS_DIR = srcs
GNL_DIR = get_next_line

SRCS = $(SRCS_DIR)/main.c \
       $(SRCS_DIR)/init.c \
	   $(SRCS_DIR)/utiles.c \

GNL_SRCS = $(GNL_DIR)/get_next_line.c \
           $(GNL_DIR)/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
GNL_OBJS = $(GNL_SRCS:.c=.o)

MLX_DIR = MLX42
MLX_LIB = $(MLX_DIR)/build/libmlx42.a

all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(NAME): $(OBJS) $(GNL_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(GNL_OBJS) $(MLX_LIB) $(MLXFLAGS) -o $(NAME)
	@echo "✅ cub3D compiled successfully!"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(GNL_OBJS)
	@if [ -f $(MLX_DIR)/Makefile ]; then make -C $(MLX_DIR) clean; fi
	@echo "🧹 Object files cleaned"


fclean: clean
	rm -f $(NAME)
	@echo "🗑️  Executable removed"

re: fclean all

.PHONY: all clean fclean re