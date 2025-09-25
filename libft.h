#ifndef LIBFT_H
#define LIBFT_H

#include <string.h>
#include <stdlib.h>

int		ft_atoi(const char *src);
int		ft_strlen(const char *src);
int		ft_isalpha(int ch);
int		ft_isdigit(int dig);
int		ft_isascii(int ch);
int		ft_isprint(int ch);
int		ft_isalnum(const int ch);
char	*ft_strdup(const char *src);
void	ft_bzero(void *dest, size_t  len);
void	*ft_calloc(size_t quant, size_t len);
void	*ft_memset(void *dest, int ch, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t size);

#endif
