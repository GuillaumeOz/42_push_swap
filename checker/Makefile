# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 14:46:10 by gozsertt          #+#    #+#              #
#    Updated: 2021/07/16 14:30:53 by gozsertt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =   checker

CC          =   gcc

SRC_DIR		= 	$(shell find srcs -type d)
INC_DIR		= 	$(shell find includes -type d)
LIB_DIR		=	libft
OBJ_DIR		=	obj
LIB 		=	ft		

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

SRC			= 	checker.c   checker_error.c   checker_parse_tab.c  					\
				checker_parse_a_stack.c  checker_set_elements_pos.c  				\
				checker_parsing.c   checker_get_next_line.c     					\
				checker_t_stack_getter.c  checker_t_stack.c  						\
				checker_t_stack_setter.c  checker_t_stack_node_getter.c   			\
				checker_t_swap_calc_rrr_setter.c  checker_t_swap_calc_getter.c		\
				checker_t_swap_calc.c  checker_t_swap_calc_setter.c  				\
				checker_t_swap_calc_rr_setter.c   checker_refresh_b_stack.c  		\
				checker_get_swap_calc_b_stack_size.c  								\
				checker_set_swap_calc_b_stack_size.c   checker_refresh_a_stack.c  	\
				checker_get_swap_calc_a_stack_size.c  								\
				checker_set_swap_calc_a_stack_size.c   checker_rrr_swap.c  			\
				checker_rb_swap.c  checker_pa_swap.c  checker_rr_swap.c  			\
				checker_sb_swap.c  checker_rra_swap.c  checker_pb_swap.c  			\
				checker_ss_swap.c  checker_rrb_swap.c  checker_ra_swap.c  			\
				checker_sa_swap.c   checker_calc_stack_len.c

OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

# Compilation flags

CFLAGS      =	-Wall -Wextra -Werror

IFLAGS		=	$(foreach dir, $(INC_DIR), -I $(dir))

LFLAGS		=	$(foreach dir, $(LIB_DIR), -L $(dir)) \
				$(foreach lib, $(LIB), -l $(lib))

# Colors

_GREY=	$'\e[30m
_RED=	$'\e[31m
_GREEN=	$'\e[32m
_YELLOW=$'\e[33m
_BLUE=	$'\e[34m
_PURPLE=$'\e[35m
_CYAN=	$'\e[36m
_WHITE=	$'\e[37m

# MAIN part --------------------------------------------------------

all:
	@echo "\n$(_BLUE)___$(NAME) Setting___\n$(_WHITE)"
	@make $(NAME)

bonus: all

show:
	@echo "$(_BLUE)SRC :\n$(_YELLOW)$(SRC)$(_WHITE)"
	@echo "$(_BLUE)OBJ :\n$(_YELLOW)$(OBJ)$(_WHITE)"
	@echo "$(_BLUE)CFLAGS :\n$(_YELLOW)$(CFLAGS)$(_WHITE)"
	@echo "$(_BLUE)IFLAGS :\n$(_YELLOW)$(IFLAGS)$(_WHITE)"
	@echo "$(_BLUE)LFLAGS :\n$(_YELLOW)$(LFLAGS)$(_WHITE)"
	@echo "$(_BLUE)LIB_DIR :\n$(_YELLOW)$(LIB_DIR)$(_WHITE)"
	@echo "\n-----\n"
	@echo "$(_BLUE)Compiling : \n$(_YELLOW)$(CC) $(CFLAGS) $(OBJ) -o $(NAME)$(_WHITE)"

install:
	@$(foreach dir, $(LIB_DIR), make -C $(dir);)

re-install:
	@$(foreach dir, $(LIB_DIR), make -C $(dir) re;)

fclean-install:
	@$(foreach dir, $(LIB_DIR), make -C $(dir) fclean;)

$(NAME): install $(OBJ)
	@echo "-----\nCreating Binary File $(_YELLOW)$@$(_WHITE) ... \c"
	@$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME)
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

$(OBJ_DIR)/%.o : %.c
	@echo "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
	@echo "$(_GREEN)DONE$(_WHITE)"

re:	fclean all

clean:
	@echo "$(_WHITE)Deleting Objects Directory $(_YELLOW)$(OBJ_DIR)$(_WHITE) ... \c"
	@$(foreach file, $(OBJ), rm -rf $(file))
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

fclean:	clean
	@echo "Deleting Binary File $(_YELLOW)$(NAME)$(_WHITE) ... \c"
	@rm -f $(NAME)
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

.PHONY: all bonus show install re-install fclean-install re clean flcean