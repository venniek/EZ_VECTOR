GCC = gcc
FLAGS = -Wall -Wextra -Werror
DIR_MLX = ./minilibx_opengl_20191021/
FLAGS_MLX = -L $(DIR_MLX) -lmlx -lz -framework OpenGL -framework Appkit
TARGET = miniRT

DIR_MAN = ./mandatory/
DIR_LIBFT = ./libft/
DIR_GNL = ./get-next-line/

MAN = mandatory.a
LIBFT = libft.a
MLX = libmlx.a
GNL = gnl.a


all : submake $(TARGET)
$(TARGET) : $(addprefix $(DIR_MAN), $(MAN)) \
$(addprefix $(DIR_LIBFT), $(LIBFT)) \
$(addprefix $(DIR_MLX), $(MLX)) \
$(addprefix $(DIR_GNL), $(GNL))
	$(GCC) $(FLAGS_MLX) -o $@ $^

$(addprefix $(DIR_MAN), $(MAN)) :
	@make -C $(DIR_MAN) all;
$(addprefix $(DIR_LIBFT), $(LIBFT)) : 
	@make -C $(DIR_LIBFT) all;
$(addprefix $(DIR_MLX), $(MLX)) : 
	@make -C $(DIR_MLX) all;
$(addprefix $(DIR_GNL), $(GNL)) : 
	@make -C $(DIR_GNL) all;

submake :
	@make -C $(DIR_MAN) all;
	@make -C $(DIR_LIBFT) all;
	@make -C $(DIR_MLX) all;
	@make -C $(DIR_GNL) all;
fclean : 
	@make -C $(DIR_MAN) fclean;
	@make -C $(DIR_LIBFT) fclean;
	@make -C $(DIR_GNL) fclean;
	@make -C $(DIR_MLX) clean;
	rm -f $(TARGET)
clean : 
	@make -C $(DIR_MAN) clean;
	@make -C $(DIR_LIBFT) clean;
	@make -C $(DIR_MLX) clean;
	@make -C $(DIR_GNL) clean;
re : fclean all
PHONY : all fclean clean re
