/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmunoz-r <cmunoz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:22:42 by cmunoz-r          #+#    #+#             */
/*   Updated: 2019/12/08 13:43:26 by cmunoz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				ft_atoi(const char *str);
void			ft_bzero(void *str, size_t len);
void			*ft_calloc(size_t count, size_t size);
int				ft_isalnum(int asc);
int				ft_isalpha(int asc);
int				ft_isascii(int asc);
int				ft_isdigit(int asc);
int				ft_isprint(int asc);
char			*ft_itoa(int n);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstadd_front(t_list **alst, t_list *new);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
							void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
void			*ft_memccpy(void *dst, const void *src,
							int c, size_t len);
void			*ft_memchr(const void *str, int c, size_t n);
int				ft_memcmp(const void *str, const void *ptr, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t len);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *str, int asc, size_t len);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *str, int fd);
void			ft_putnbr_fd(long long nbr, int fd);
void			ft_putstr_fd(char *str, int fd);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strchr(const char *str, int asc);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdup(const char *src);
char			*ft_strjoin(char const *str, char const *ptr);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);
char			*ft_strmapi(char const *str, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strrchr(const char *str, int asc);
char			*ft_strtrim(char const *str, char const *set);
char			**ft_split(char const *str, char c);
char			*ft_substr(char const *str, unsigned int start, size_t len);
char			*ft_strnstr(const char *haystack,
							const char *needle, size_t len);
int				ft_tolower(int asc);
int				ft_toupper(int asc);
int				get_next_line(int fd, char **line);

#endif
