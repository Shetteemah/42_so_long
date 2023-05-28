NAME	=	so_long
UNAME_S	:=	$(shell uname -s)

CYAN=\033[0;36m
GREEN=\033[0;32m
MAGENTA=\033[0;35m
ENDCOLOR=\033[0m

CC= cc
FLAGS= -Wall -Werror -Wextra

OBJ			=	obj/add_squares.o \
				obj/build_map.o \
				obj/collectible.o \
				obj/eject.o \
				obj/elements.o \
				obj/find_exit_path.o \
				obj/launch.o \
				obj/main.o \
				obj/map.o \
				obj/movement.o \
				obj/position.o \
				obj/print_error.o \
				obj/read_map.o \
				obj/so_long.o \
				obj/squares.o \
				obj/utils_sqr.o \
				obj/structure.o \
				obj/utils.o \

MLX			=	libs/MLX42/build/libmlx42.a
MLX_H		=	libs/MLX42/include/MLX42/MLX42.h
LIBFT		=	obj/libft/libft.o
LIBFT_DIR	=	libft/
NAME_H		=	includes/so_long.h

ifeq ($(UNAME_S),Linux)
MLX_FLAGS	=	-ldl -lglfw -pthread -lm
endif
ifeq ($(UNAME_S),Darwin)
MLX_FLAGS	=	-lglfw -L /opt/homebrew/Cellar/glfw/3.3.8/lib
endif

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJ) $(NAME_H) 
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)


obj/%.o: src/%.c
	$(CC) -g -Wall -Wextra -Werror -c $< -o $@


$(LIBFT): $(LIBFT_DIR)/*.c
	@if  [ ! -d obj/libft ]; then \
		mkdir -p obj/libft; \
	fi
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a $(LIBFT)
	@make fclean -C $(LIBFT_DIR)

$(MLX): $(MLX_H)
	@cd libs/MLX42; cmake -B build; cmake --build build -j4

$(MLX_H):
	git submodule init
	git submodule update

clean:
	@echo "$(MAGENTA)Cleaning object files.. $(ENDCOLOR)"
	@$(RM) $(OBJ) $(BONUS_OBJ) $(MLX) 
	@rm -rf /libs/MLX42/build;

fclean: clean
	@echo "$(MAGENTA)Cleaning all.. $(ENDCOLOR)"
	@$(RM) $(NAME) $(BONUS) $(LIBFT)

re: clean all

.PHONY: all clean fclean re 
