# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/26 10:50:48 by inowak--          #+#    #+#              #
#    Updated: 2024/12/04 14:12:23 by inowak--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color #

RED    = \033[1;31m
GREEN  = \033[1;32m
YELLOW = \033[1;33m
BLUE   = \033[1;34m
PURPLE = \033[1;35m
RESET  = \033[0m

NAME = push_swap

CC = cc
CFLAGS := -Wall -Wextra -Werror -g
AR = ar rcs

PRINTF_FILES = lib/ft_printf/ft_pointer.c\
				lib/ft_printf/ft_put.c\
				lib/ft_printf/ft_printf_handle.c\
				lib/ft_printf/ft_printf.c\

SRC = ft_algo_ptt.c\
		ft_algo_tools.c\
		ft_algo_moves_a.c\
		ft_algo_moves_b.c\
		ft_algo.c\
		ft_check_tools.c\
		ft_check.c\
		ft_split.c\
		main.c\


OBJ = $(SRC:.c=.o)
OBJ_LIB = $(PRINTF_FILES:.c=.o)

all: $(NAME)
	@echo "";
	@echo "$(PURPLE) ######   ##   ##   #####   ##   ##            #####   ##   ##    ##     ######$(RESET)";
	@echo "$(PURPLE)  ##  ##  ##   ##  ##   ##  ##   ##           ##   ##  ##   ##   ####     ##  ##$(RESET)";
	@echo "$(PURPLE)  ##  ##  ##   ##  #        ##   ##           #        ##   ##  ##  ##    ##  ##$(RESET)";
	@echo "$(PURPLE)  #####   ##   ##   #####   #######            #####   ## # ##  ##  ##    #####$(RESET)";
	@echo "$(PURPLE)  ##      ##   ##       ##  ##   ##                ##  #######  ######    ##$(RESET)";
	@echo "$(PURPLE)  ##      ##   ##  ##   ##  ##   ##           ##   ##  ### ###  ##  ##    ##$(RESET)";
	@echo "$(PURPLE) ####      #####    #####   ##   ##            #####   ##   ##  ##  ##   ####$(RESET)";
	@echo "";
	@echo "$(GREEN)$(NAME)$(RESET)$(YELLOW) is uptade$(RESET).";

$(NAME): $(OBJ) $(OBJ_LIB)
	@$(CC) $(OBJ) $(OBJ_LIB) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJ_LIB)
	@echo "$(RED)clean$(RESET)";

fclean: clean
	@echo "$(YELLOW)remove$(YELLOW) $(RED)$(NAME)$(RESET)";
	@rm -f $(NAME)

re: fclean all
	@echo "$(NAME) restart"

.PHONY: all clean fclean re
