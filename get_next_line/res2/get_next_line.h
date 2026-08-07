#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *str1, char *str2);
void	ft_bzero(char *str, int n);
char	*ft_calloc(int n, int size);
char	*ft_strchr(char *str, char c);
int	ft_strlen(char *str);

#endif
