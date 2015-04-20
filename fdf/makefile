# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/26 15:40:22 by sde-toda          #+#    #+#              #
#    Updated: 2015/02/10 17:17:30 by sde-toda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

GCC = gcc

FLAGS = -Wall -Werror -Wextra -I includes/ -g
LFLAGS = -L libft/ -lft -L /usr/X11/lib -lft -lmlx -lX11 -lXext -lm

LIBFT = ./libft/libft.a
DO_LIBFT = make -C libft/
CL_LIBFT = make -C libft/ clean
FCL_LIBFT = make -C libft/ fclean

SRC = fdf.c ft_getnbr.c ft_init_map.c ft_new_point.c ft_insert_elem.c 
SRC += free_line.c get_map.c project_iso.c ft_go_first_point.c
SRC += ft_destroy_lst.c ft_destroy_point.c set_point.c draw.c ft_min.c
SRC += put_pix_to_img.c gere_mlx.c gere_key.c kill_everything.c print_msgs.c
SRC += print_menu.c


OBJ = $(SRC:.c=.o)

SRCD = srcs/
OBJD = objs/
SRCS = $(addprefix $(SRCD), $(SRC))
OBJS = $(addprefix $(OBJD), $(OBJ))

.PHONY = all clean fclean re norme

$(NAME): $(OBJS) $(LIBFT)
	@echo "\\033[1;36mMaking Objects..."
	$(GCC) -o $(NAME) $(OBJS) $(LFLAGS)
	@echo "\\033[6;32mFDF STATUS = DONE"

$(LIBFT):
	@echo "\\033[1;36mMaking Lib..."
	@$(DO_LIBFT)

$(OBJD)%.o: $(SRCD)%.c
	@mkdir $(OBJD) 2> /dev/null || echo '' > /dev/null
	@$(GCC) $(FLAGS) -o $@ -c $<

all: $(NAME)

clean: 
		@rm -f $(OBJS)
		@rm -rf $(OBJD)
		@$(CL_LIBFT)
		@echo "\\033[2;31mCleaning Objects..."

fclean: clean
	@echo "Cleaning Libft.a and fdf.."
	rm -f $(NAME)
	rm -f $(LIBFT)
	@$(FCL_LBFT)

re: fclean all

norme:
	@make -C libft/ norme
	@norminette $(SRCS) 
	@norminette "includes/"
