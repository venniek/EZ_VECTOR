GCC = gcc
FLAGS = -Wall -Wextra -Werror
FLAGS_MLX = -L $(DIR_MLX) -lmlx -framework OpenGL -framework Appkit
TARGET = miniRT
DIR_MLX = ./minilibx_opengl_20191021/
LIBFT = libft.a
MLX = libmlx.a
GNL = gnl.a

DIR_SRCS = ./mandatory/srcs/
DIR_HEARDER = ./mandatory/incs/
DIR_LIBFT = ./libft/
DIR_GNL = ./get-next-line/
SRCS = main.c \
	light.c\
	mlx_hook.c\
	parsing.c \
	parsing_viewer.c\
	three_value_2.c\
	viewer.c\
	main.c\
	mlx_img.c\
	parsing_object.c\
	ray.c\
	three_value_vector.c\
	matrix.c\
	object.c\
	parsing_utils.c\
	three_value_1.c\
	utils.c
OBJS = $(SRCS:.c=.o)


all : $(TARGET)
$(TARGET) : $(addprefix $(DIR_SRCS), $(OBJS)) \
$(addprefix $(DIR_LIBFT), $(LIBFT)) \
$(addprefix $(DIR_MLX), $(MLX)) \
$(addprefix $(DIR_GNL), $(GNL))
	$(GCC) $(FLAGS_MLX) -o $@ $^
%.o : %.c
	$(GCC) $(FLAGS) -c -o $@ $^ -I $(DIR_HEARDER)
$(addprefix $(DIR_LIBFT), $(LIBFT)) : 
	@make -C $(DIR_LIBFT) all;
	@make -C $(DIR_LIBFT) bonus;
$(addprefix $(DIR_MLX), $(MLX)) : 
	@make -C $(DIR_MLX) all;
$(addprefix $(DIR_GNL), $(GNL)) : 
	@make -C $(DIR_GNL) all;
fclean : 
	@rm -rf $(TARGET);
	@make -C $(DIR_LIBFT) fclean;
	@make -C $(DIR_GNL) fclean;
clean : 
	@rm -rf $(addprefix $(DIR_SRCS), $(OBJS));
	@make -C $(DIR_LIBFT) clean;
	@make -C $(DIR_MLX) clean;
	@make -C $(DIR_GNL) clean;
re : clean fclean all
PHONY : all fclean clean re