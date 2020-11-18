/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbari <mbari@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:51:44 by mbari             #+#    #+#             */
/*   Updated: 2020/11/17 12:23:52 by mbari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "../includes/libftprintf.h"
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

void		*ft_memset(void *ptr, int x, size_t len);
void		ft_bzero(void *ptr, size_t l);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memchr(const void *str, int c, size_t n);
void		*ft_calloc(size_t count, size_t size);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
char		*ft_strnstr(const char *big, const char *little,
						size_t len);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_itoa(int n);
int			ft_intsize(int n);
void		ft_putchar(const char c, t_print *val);
void		ft_putstr(const char *s, t_print *val);
void		ft_putendl(const char *s, t_print *val);
void		ft_putnbr(long long n, t_print *val);
void		ft_putunsignednbr(unsigned int n, t_print *val);
int			ft_atoi(const char *str);
int			ft_isalnum(int a);
int			ft_isalpha(int c);
int			ft_isascii(int asci);
int			ft_isdigit(int c, t_print *val);
int			ft_isprint(int p);
char		*ft_strchr(const char *str, int c);
size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *str, int c);
int			ft_strncmp(const char *str1, const char *str2, size_t n);
char		*ft_strrchr(const char *s, int r);
int			ft_tolower(int c);
int			ft_toupper(int i);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char		*ft_strrev(char *str);
char		*ft_strcat(char *dest, char *src);
int			my_atoi(char **str);

#endif
