/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 07:49:33 by adraji            #+#    #+#             */
/*   Updated: 2025/12/25 09:10:49 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// --- REQUIRED LIBRARIES ---

# include <stdlib.h>
# include <unistd.h>

// --- PREVENTS REDEFINITON CONFLICTS IF THE STANDARD <limits.h> HEADER ---

//	Prevents redefinition conflicts if the standard <limits.h> header
//		is also included.
# ifndef LONG_MAX
#  define LONG_MAX __LONG_MAX__
# endif

//	Alias for LONG_MAX to comply with the Norminette's 80-column limit
//		in functions (ft_atoi.c).
# define LM LONG_MAX

//	Guard against redefinition of SIZE_MAX, similar to LONG_MAX,
//		often needed for system compatibility.
# ifndef SIZE_MAX
#  define SIZE_MAX __SIZE_MAX__
# endif

// --- MACROS FOR SIMPLIFY THE CODE ---

# define PLUS 1
# define MINUS -1
# define TRUE 1
# define FALSE 0

// --- TYPEDEF & STRUCT ---
typedef char	t_signe;
typedef char	t_bool;

//	struct:
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// --- FUNCTIONS THAT ARE IN THE LIBRARY ---

//	memory:
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

//	string:
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

//	char:
t_bool	ft_isalpha(int c);
t_bool	ft_isdigit(int c);
t_bool	ft_isalnum(int c);
t_bool	ft_isascii(int c);
t_bool	ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

//	convert
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);

//	io:
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

//	alloc:
void	*ft_calloc(size_t count, size_t size);

//	list:
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void*));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*));

#endif