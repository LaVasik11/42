#include "ft_printf.h"

int	parse(char c, va_list args)
{
	if (c == 'c')
		return (ft_putc((char)va_arg(args, int)));
	else if (c == 's')
		return (ft_puts(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putd(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putu(va_arg(args, unsigned int)));
	else if (c == 'p')
		return (ft_putp(va_arg(args, unsigned long long)));
	else if (c == 'x')
		return (ft_putx(va_arg(args, unsigned int), 0));
	else if (c == 'X')
		return (ft_putx(va_arg(args, unsigned int), 1));
	else
		return (ft_putc('%'));
}

int	ft_printf(const char *format, ...)
{
	int	i;
	int	res;
	va_list	args;

	va_start(args, format);
	i = 0;
	res = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			res += parse(format[i + 1], args);
			i++;
		}
		else
			res += ft_putc(format[i]);
		i++;
	}
	va_end(args);
	return (res);
}
