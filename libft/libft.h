/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukoltso <rukoltso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:45:23 by rukoltso          #+#    #+#             */
/*   Updated: 2023/12/04 16:01:08 by rukoltso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdarg.h>

#define MAX(a, b) (a > b ? a : b)

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct	s_list
{
	void *content;
	struct s_list *next;
}	t_list;

int		ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char 		*ft_strjoin(char *s1, char *s2);
char 		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char			**ft_strsplit(char const *str, char c);
char		*ft_itoa(int n);
char 		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_tolower(int c);
int		ft_toupper(int c);

char	*get_next_line(int fd);
long	ft_charsrch(const char *str, char c);
char	*empty_line(void);
void	str_move(char **str, size_t start);
long	ft_charsrch(const char *str, char c);
int		ft_word_counter(char const *str, char c);

int		ft_print_char(int c);
int		ft_print_str(const char *str);
int		ft_print_nbr(int n);
int		ft_print_percent(void);
int		ft_print_unsigned(unsigned int num);
int		ft_unbr_len(unsigned int num);
int		ft_print_hex(unsigned int num, const char format);
int		ft_hex_len(unsigned int num);
int		ft_pointer_len(uintptr_t num);
int		ft_print_pointer(unsigned long long num);
int		ft_printf(const char *str, ...);

char	*ft_uitoa(unsigned int nb);
char	*ft_itoa(int n);

void	ft_put_str(const char *str);
void	ft_put_ptr(uintptr_t num);
void	ft_put_hex(unsigned int num, const char format);
void	ft_putchar_fd(char c, int fd);
#endif