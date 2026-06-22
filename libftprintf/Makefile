NAME		= libftprintf.a
LIBFT_DIR	= libft
HEADER		= ft_printf.h ft_printf_data_utils.h $(LIBFT_DIR)/libft.h

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
AR			= ar rcs

# --- SOURCE FILES ---
SRC_LIBFT	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
			  ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
			  ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			  ft_putnbr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
			  ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
			  ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
			  ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
			  ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
			  ft_lstmap_bonus.c

SRC_PRINTF	= ft_parse_flags.c ft_print_ptr_fms.c ft_print_char_fms.c ft_print_str_fms.c \
			  ft_printf.c ft_print_hex_fms.c ft_print_unsigned_fms.c ft_printf_data_utils.c \
			  ft_print_int_fms.c ft_putchar_len.c

SRC			= $(addprefix $(LIBFT_DIR)/, $(SRC_LIBFT)) $(SRC_PRINTF)
OBJ			= $(SRC:.c=.o)

# --- RULES ---

all:		$(NAME)

$(NAME):	$(OBJ)
	$(AR) $(NAME) $(OBJ)

# Rule for object files with Header dependency to avoid relink issues
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus:		all

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:		clean