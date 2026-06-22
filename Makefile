# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adraji <adraji@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/28 16:40:00 by adraji            #+#    #+#              #
#    Updated: 2025/12/30 18:35:21 by adraji           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
BONUS_NAME		= checker
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -fsanitize=address,leak
RM				= rm -f

# --- LIBRARIES ---
LIB_DIR			= libftprintf
LIBFTPRINTF		= $(LIB_DIR)/libftprintf.a

# --- DIRECTORIES ---
OPS_DIR			= operations
PARS_DIR		= parsing
STK_DIR			= stack_utils
SORT_DIR		= sorting
BONUS_DIR		= bonus

# --- HEADERS ---
# Monitoring headers to trigger recompilation if they change
M_HDRS			= ft_push_swap.h $(PARS_DIR)/ft_parsing.h $(SORT_DIR)/ft_sort_utils.h
B_HDRS			= $(BONUS_DIR)/ft_checker.h $(BONUS_DIR)/get_next_line/get_next_line.h \
				  $(BONUS_DIR)/parsing/ft_parsing.h ft_push_swap.h

# --- MANDATORY SOURCES ---
M_SRCS			= ft_push_swap.c ft_error_utils.c ft_mem_manager.c ft_stack_init.c \
				  $(OPS_DIR)/ft_rotate.c $(OPS_DIR)/ft_push.c \
				  $(OPS_DIR)/ft_reverse_rotate.c $(OPS_DIR)/ft_swap.c \
				  $(PARS_DIR)/ft_atoi_ilimit.c $(PARS_DIR)/ft_parsing.c $(PARS_DIR)/ft_strsjoin_check.c \
				  $(STK_DIR)/ft_stack_analysis.c $(STK_DIR)/ft_stack_indexing.c \
				  $(SORT_DIR)/ft_sorting.c $(SORT_DIR)/ft_sort_prep.c $(SORT_DIR)/ft_sort_utils.c \
				  $(SORT_DIR)/ft_prepare_push_b.c $(SORT_DIR)/ft_prepare_push_a.c

# --- BONUS SOURCES ---
BONUS_PATH		= $(BONUS_DIR)/
B_GNL			= $(BONUS_PATH)get_next_line/
B_OPS			= $(BONUS_PATH)operations/
B_PARS			= $(BONUS_PATH)parsing/

B_SRCS			= $(BONUS_PATH)ft_checker.c \
				  $(BONUS_PATH)ft_apply_operations.c \
				  $(BONUS_PATH)ft_mem_manager.c \
				  $(BONUS_PATH)ft_print_status.c \
				  $(BONUS_PATH)ft_stack_init.c \
				  $(B_GNL)get_next_line.c $(B_GNL)get_next_line_utils.c \
				  $(B_OPS)ft_push_silence.c $(B_OPS)ft_reverse_rotate_silence.c \
				  $(B_OPS)ft_rotate_silence.c $(B_OPS)ft_swap_silence.c \
				  $(B_PARS)ft_parsing.c $(B_PARS)ft_parsing_utils.c \
				  $(B_PARS)ft_strsjoin_check.c

# --- OBJECTS ---
M_OBJS			= $(M_SRCS:.c=.o)
B_OBJS			= $(B_SRCS:.c=.o)

# --- RULES ---

all:			$(NAME)

# Link mandatory
$(NAME):		$(M_OBJS) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(M_OBJS) $(LIBFTPRINTF) -o $(NAME)

# Link bonus
bonus:			$(BONUS_NAME)

$(BONUS_NAME):	$(B_OBJS) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(B_OBJS) $(LIBFTPRINTF) -o $(BONUS_NAME)

# Build library
$(LIBFTPRINTF):	force
	@$(MAKE) -C $(LIB_DIR)

# Compilation for Mandatory (depends on M_HDRS)
$(M_OBJS): %.o: %.c $(M_HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

# Compilation for Bonus (depends on B_HDRS)
$(B_OBJS): %.o: %.c $(B_HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(M_OBJS) $(B_OBJS)
	@$(MAKE) -C $(LIB_DIR) clean

fclean:			clean
	$(RM) $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(LIB_DIR) fclean

re:				fclean all
reb:				fclean bonus

force:

.PHONY:			all clean fclean re bonus force