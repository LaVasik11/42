#include "ft_printf.h"

int	ft_putc(char c)
{
	return (write(1, &c, 1));
}

int	ft_puts(char *str)
{
	int	i;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i])
		ft_putc(str[i++]);
	return (i);
}
