#include "ft_printf.h"

int	ft_putp(unsigned long long n)
{
	char	*digits = "0123456789abcdef";
	char	buffer[17];
	int	i;
	int	res;

	if (n == 0)
		return (write(1, "(nil)", 5));
	res = 0;
	i = 15;
	buffer[16] = 0;
	while (n > 0)
	{
		buffer[i--] = digits[n % 16];
		n /= 16;
	}
	res += write(1, "0x", 2);
	res += ft_puts(&buffer[i + 1]);
	return (res);
}
