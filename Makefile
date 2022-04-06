GCC = gcc
FLAGS = -Wall -Wextra -Werror
FLAGS_MLX = -L $(DIR_MLX) -lmlx -lz -framework OpenGL -framework Appkit
TARGET = miniRT
TARGET_BONUS = miniRT_bonus

DIR_MLX = ./minilibx_opengl_20191021/
DIR_MAN = ./mandatory/
DIR_BONUS = ./bonus/
DIR_LIBFT = libft/
DIR_GNL = ./get-next-line/

MAN = mandatory.a
BONUS = bonus.a
LIBFT = libft.a
MLX = libmlx.a
GNL = gnl.a

all : submake $(TARGET)
$(TARGET) : $(addprefix $(DIR_MAN), $(MAN))\
$(addprefix $(DIR_MLX), $(MLX))\
$(addprefix $(DIR_LIBFT), $(LIBFT))\
$(addprefix $(DIR_GNL), $(GNL))
	$(GCC) $(FLAGS_MLX) -o $@ $^

bonus : submake_bonus $(TARGET_BONUS)
$(TARGET_BONUS) : $(addprefix $(DIR_BONUS), $(BONUS))\
$(addprefix $(DIR_MLX), $(MLX))\
$(addprefix $(DIR_LIBFT), $(LIBFT))\
$(addprefix $(DIR_GNL), $(GNL))
	$(GCC) $(FLAGS_MLX) -o $@ $^

submake : man mlx gnl libft

submake_bonus : bon mlx gnl libft

man : 
	@make -C $(DIR_MAN) all;

bon :
	@make -C $(DIR_BONUS) all;

mlx : 
	@make -C $(DIR_MLX) all;

libft :
	@make -C $(DIR_LIBFT) all;

gnl : 
	@make -C $(DIR_GNL) all;

fclean : 
	@make -C $(DIR_MAN) fclean;
	@make -C $(DIR_BONUS) fclean;
	@make -C $(DIR_LIBFT) fclean;
	@make -C $(DIR_GNL) fclean;
	@make -C $(DIR_MLX) clean;
	rm -f $(TARGET) $(TARGET_BONUS)
clean : 
	@make -C $(DIR_MAN) clean;
	@make -C $(DIR_BONUS) clean;
	@make -C $(DIR_LIBFT) clean;
	@make -C $(DIR_MLX) clean;
	@make -C $(DIR_GNL) clean;

re : fclean all
re_bonus : fclean bonus

.PHONY : all fclean clean re submake libft man gnl mlx bonus bon submake_bonus