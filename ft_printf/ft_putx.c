#include "ft_printf.h"

int	ft_putx(unsigned int n, int isup)
{
	int	i;
	char	buffer[9];
	char	*digits;

	if (n == 0)
        	return (write(1, "0", 1));
	i = 7;
	buffer[8] = 0;
	if (isup)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	while (n > 0)
	{
		buffer[i--] = digits[n % 16];
		n /= 16;
	}
	return (ft_puts(&buffer[i + 1]));
}
