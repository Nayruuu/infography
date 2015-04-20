# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/26 15:40:22 by sde-toda          #+#    #+#              #
#    Updated: 2015/02/27 14:09:46 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

GCC = gcc

FLAGS = -Wall -Werror -Wextra -O3 -I includes/ -g
LFLAGS = -O3 -L libft/ -lft -L /usr/X11/lib -lft -lmlx -lX11 -lXext -lm

LIBFT = ./libft/libft.a
DO_LIBFT = make -C libft/
CL_LIBFT = make -C libft/ clean
FCL_LIBFT = make -C libft/ fclean

SRC = fractol.c set_point.c mandelbrot.c julia.c phoenix.c escher.c
SRC += gere_mlx.c gere_key.c gere_mouse.c gere_cam.c put_pix_to_img.c
SRC += complex_calc.c burning_ship.c barnsley.c square.c unity.c
SRC += kill_everything.c color.c

OBJ = $(SRC:.c=.o)

SRCD = srcs/
OBJD = objs/
SRCS = $(addprefix $(SRCD), $(SRC))
OBJS = $(addprefix $(OBJD), $(OBJ))

.PHONY = all clean fclean re norme

$(NAME): $(LIBFT) $(OBJS)
	@$(GCC) -o $(NAME) $(OBJS) $(LFLAGS)
	@echo "\\033[0;32mFRACTOL STATUS = DONE"
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
	@$(GCC) $(FLAGS) -o $@ -c $<
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
	@echo "Cleaning Libft.a and fractol.."
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
