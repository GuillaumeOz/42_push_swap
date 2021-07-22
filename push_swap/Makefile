# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 14:46:10 by gozsertt          #+#    #+#              #
#    Updated: 2021/07/20 20:17:06 by gozsertt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =   push_swap

CC          =   gcc

SRC_DIR		= 	$(shell find srcs -type d)
INC_DIR		= 	$(shell find includes -type d)
LIB_DIR		=	libft
OBJ_DIR		=	obj
LIB 		=	ft		

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

SRC			= 	push_swap.c   push_swap_error.c   push_swap_parse_tab.c								\
				push_swap_parse_a_stack.c  push_swap_set_elements_pos.c 							\
				push_swap_parsing.c   push_swap_simple_sort.c  										\
				push_swap_rotation_counter.c  push_swap_backtracking_sort.c  						\
				push_swap_apply_rotation.c  push_swap_sort_types.c  								\
				push_swap_medium_sort.c  push_swap_long_sort.c  									\
				push_swap_low_sort.c  push_swap_low_a_sort_switch_cases.c  							\
				push_swap_low_b_sort_switch_cases.c  push_swap_start_sort.c     					\
				push_swap_t_stack_getter.c  push_swap_t_stack.c  									\
				push_swap_t_stack_setter.c  push_swap_t_stack_node_getter.c   						\
				push_swap_t_swap_calc_rr_setter.c  													\
				push_swap_t_swap_calc_rrr_setter.c  												\
				push_swap_t_swap_calc_getter.c  push_swap_t_swap_calc.c  							\
				push_swap_t_swap_calc_setter.c   push_swap_refresh_b_stack.c  						\
				push_swap_get_swap_calc_b_stack_size.c  											\
				push_swap_set_swap_calc_b_stack_size.c   											\
				push_swap_get_swap_calc_a_stack_size.c  											\
				push_swap_set_swap_calc_a_stack_size.c  											\
				push_swap_refresh_a_stack.c   push_swap_ra_swap.c  									\
				push_swap_sa_swap.c  push_swap_sb_swap.c  push_swap_rr_swap.c  						\
				push_swap_pa_swap.c  push_swap_rra_swap.c  push_swap_pb_swap.c  					\
				push_swap_rrb_swap.c  push_swap_ss_swap.c  push_swap_rrr_swap.c  					\
				push_swap_rb_swap.c   push_swap_load_rb_rra_way.c  									\
				push_swap_calc_stack_len.c  push_swap_over_check.c  push_swap_load_rr_way.c			\
				push_swap_compute_rrr_cmd.c  push_swap_load_rrr_way.c  push_swap_set_low_start.c	\
				push_swap_load_ra_rrb_way.c  push_swap_compute_rr_cmd.c

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

.PHONY: all show install re-install fclean-install re clean flcean