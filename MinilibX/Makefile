# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/22 23:12:10 by pbondoer          #+#    #+#              #
#    Updated: 2017/09/29 16:43:00 by eferrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include libmlx.mk

all: $(MLX_LIB)

$(MLX_LIB):
	@make -C $(MLX_DIR)
	cp $(MLX_LIB) $(MLX_NAME)
	cp sierra/mlx.h ./

clean:
	make -C $(MLX_DIR) clean
	rm -f $(MLX_NAME)

fclean: clean

re:
	@$(MAKE) clean --no-print-directory
	@$(MAKE) all --no-print-directory
