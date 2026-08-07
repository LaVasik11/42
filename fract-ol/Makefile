NAME         = fractol

CC           = cc
CFLAGS       = -Werror -Wextra -Wall

MLX_PATH     = minilibx-linux/
MLX_NAME     = libmlx.a
MLX          = $(MLX_PATH)$(MLX_NAME)

LIBFT_PATH   = libft/
LIBFT_NAME   = libft.a
LIBFT        = $(LIBFT_PATH)$(LIBFT_NAME)

INC          = -I ./includes/ -I ./libft/ -I ./minilibx-linux/

SRC_PATH     = src/
SRC          = fractol.c initialization.c utils.c events.c render.c color.c parse_args.c \
               fractal_sets/mandelbrot.c fractal_sets/julia.c fractal_sets/burning_ship.c \
               fractal_sets/tricorn.c fractal_sets/mandelbox.c \
               color_schemes/color_interpolated.c color_schemes/color_special.c color_schemes/color_striped.c
SRCS         = $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH     = obj/
OBJ          = $(SRC:.c=.o)
OBJS         = $(addprefix $(OBJ_PATH), $(OBJ))

all: $(MLX) $(LIBFT) $(NAME)

# Правило для сборки объектных файлов с порядковой зависимостью от каталога.
$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(dir $@)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(MLX):
	@make -C $(MLX_PATH)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INC) -lXext -lX11 -lm

bonus: all

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)

re: fclean all

.PHONY: all bonus clean fclean re

