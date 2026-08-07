#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

char	*get_next_line(int fd);
int	ft_strlen(char *str);
char	*ft_strchr(char *Str, char c);
char	*ft_calloc(int n, int size);
void	ft_bzero(char *str, int n);
char	*ft_strjoin(char *str1, char *str2);

#endif
