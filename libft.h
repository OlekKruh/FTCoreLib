/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:19:47 by okruhlia          #+#    #+#             */
/*   Updated: 2025/09/27 17:40:56 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>

int		ft_atoi(const char *src);
int		ft_strlen(const char *src);
int		ft_isalpha(int arg);
int		ft_isdigit(int dig);
int		ft_isascii(int arg);
int		ft_isprint(int arg);
int		ft_isalnum(int arg);
int		ft_memcmp(const void *str1, const void *str2, size_t len);
int		ft_tolower(int arg);
int		ft_toupper(int arg);
char	*ft_strdup(const char *src);
char	*ft_strncpy(char *dest, const char *src, size_t len);
char	*ft_strnstr(const char *str, const char *substr, size_t len);
char	*ft_strrchr(const char *str, int ch);
char	*ft_strchr(const char *str, int ch);
void	ft_bzero(void *dest, size_t len);
void	*ft_calloc(size_t quant, size_t len);
void	*ft_memset(void *dest, int ch, size_t len);
void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	*ft_memchr(const void *src, int arg, size_t len);

#endif
