#include "ft_printf.h"

int	ft_putu(unsigned int d)
{
	char	buffer[11];
	int	i;

	if (d == 0)
		return (write(1, "0", 1));
	i = 9;
	buffer[10] = 0;
	while (d > 0)
	{
		buffer[i--] = d % 10 + '0';
		d /= 10;
	}
	return (ft_puts(&buffer[i + 1]));
}

