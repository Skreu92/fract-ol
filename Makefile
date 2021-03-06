# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Etienne <etranchi@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/21 19:06:47 by Etienne           #+#    #+#              #
#    Updated: 2017/05/23 15:53:18 by etranchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS= -Wall -Wextra -Werror

SRC= dragon.c\
		julia.c\
		key.c\
		main.c\
		mandelbrot.c\
		mouse.c\
		utilities.c\
		burningship.c\
		julia2.c\
		julia3.c\
		duo.c\

NAME = fractol
CC = gcc
OBJ = $(SRC:.c=.o)
RM = rm -rf
INC = -I includes/
FRAME = -framework OpenGL -framework AppKit
FT = -L libft/ -lft
MLX = -L minlibx/ -lmlx

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/ fclean
	@make -C libft/
	@$(CC)  $(FLAGS) $(FRAME) $(INC) -o $(NAME) $(OBJ) $(FT) $(MLX)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
