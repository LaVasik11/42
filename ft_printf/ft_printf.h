#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int ft_printf(const char *fmt, ...);
int ft_putc(char c);
int ft_puts(char *s);
int ft_putd(int d);
int ft_putu(unsigned int u);
int ft_putx(unsigned int n, int isup);
int ft_putp(unsigned long long p);

#endif

