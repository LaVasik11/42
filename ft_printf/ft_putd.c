#include "ft_printf.h"

int	ft_putd(int d)
{
	char	buffer[12];
	int	i;
	int	res;

	res = 0;
	if (d == 0)
		return (write(1, "0", 1));
	if (d == INT_MIN)
		return (write(1, "-2147483648", 11));
	if (d < 0)
	{
		res += (write(1, "-", 1));
		d = -d;
	}
	i = 10;
	buffer[11] = 0;
	while (d > 0)
	{
		buffer[i--] = d % 10 + '0';
		d /= 10;
	}
	res += ft_puts(&buffer[i + 1]);
	return (res);
}
