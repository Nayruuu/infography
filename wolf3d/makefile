# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/26 15:40:22 by sde-toda          #+#    #+#              #
#    Updated: 2015/03/14 15:18:33 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

GCC = gcc

FLAGS = -Wall -Werror -Wextra -O3 -I includes/ -g
LFLAGS = -O3 -L libft/ -lft -L ./sdl2/2.0.3/lib/ -lSDL2
SDLFLAGS = -I ./sdl2/2.0.3/include/SDL2/
LIBFT = ./libft/libft.a
DO_LIBFT = make -C libft/
CL_LIBFT = make -C libft/ clean
FCL_LIBFT = make -C libft/ fclean

SRC = wolf3d.c get_map.c free_line.c check.c draw.c put_pix_to_img.c
SRC += gere_mlx.c gere_key.c gere_mouse.c check_move.c color.c
SRC += kill_everything.c dist.c draw_map.c init_pos.c

OBJ = $(SRC:.c=.o)

SRCD = srcs/
OBJD = objs/
SRCS = $(addprefix $(SRCD), $(SRC))
OBJS = $(addprefix $(OBJD), $(OBJ))

.PHONY = all clean fclean re norme

$(NAME): $(LIBFT) $(MLXLIB) $(OBJS)
	@$(GCC) -o $(NAME) $(OBJS) $(LFLAGS) $(SDLFLAGS)
	@echo "\\033[0;32mWOLF3D STATUS = DONE"
	@sleep 2
	@clear

$(LIBFT):
	@clear
	@echo "\\033[0;32mMaking Lib..."
	@sleep 1
	@$(DO_LIBFT)	
	@printf "\\033[0;32mLIBFT STATUS = DONE\n"
	@sleep 1
	@clear
	@echo "\\033[0;32mMaking Objects..."
	@sleep 1

$(OBJD)%.o: $(SRCD)%.c
	@mkdir $(OBJD) 2> /dev/null || echo '' > /dev/null
	@$(GCC) $(FLAGS) $(SDLFLAGS) -o $@ -c $<
	@printf "\\033[1;37m%-23s -\\033[0;32m->     \\033[1;34m%s\n" "$<" "$@"

all: $(NAME)

clean:	
		@clear
		@rm -f $(OBJS)
		@rm -rf $(OBJD)
		@$(FCL_LIBFT)
		@echo "\\033[2;31mCleaning Objects..."
		@sleep 2
		@clear


fclean: clean
	@echo "Cleaning Libft.a and wolf3d.."
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@$(FCL_LBFT)
	@sleep 2
	@clear

re: fclean
	@echo ""
	@make all

norme:
	@make -C libft/ norme
	@norminette $(SRCS) 
	@norminette "includes/"
