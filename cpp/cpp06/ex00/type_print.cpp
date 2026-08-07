#include "ScalarConverter.hpp"

void	print_special(const std::string& str)
{
    if (str == "-inff" || str == "-inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else if (str == "+inff" || str == "+inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (str == "nanf" || str == "nan")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
}

void	print_char(const std::string& str)
{
    char    c = 0;
    size_t  len = str.length();

	if (len == 1)
		c = str[0];
	else
		c = str[1];

	if (isprint(c))
	{
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(c) << "f" << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(c) << std::endl;
	}
	else
		std::cout << "char: Non displayable" << std::endl;
}

void	print_int(const std::string& str)
{
	long	l = std::strtol(str.c_str(), NULL, 10);

	std::cout << "char: ";
	if (l < 0 || l > 127)
		std::cout << "impossible" << std::endl;
	else
	{
		if (isprint(l))
			std::cout << "'" << static_cast<char>(l) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	std::cout << "int: ";
	if (l < MIN_INT || l > MAX_INT)
		std::cout << "impossible" << std::endl;
	else
		std::cout	<< static_cast<int>(l) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(l) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(l) << std::endl;
}

void	print_float(const std::string& str)
{
	float	f = std::strtof(str.c_str(), NULL);

	std::cout << "char: ";
	if (std::isnan(f) || f < 0 || f > 127)
		std::cout << "impossible" << std::endl;
	else if (isprint(static_cast<int>(f)))
		std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	std::cout << "int: ";
	if (std::isnan(f) || f < MIN_INT || f > MAX_INT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(f) << std::endl;

	std::cout << "float: ";
	if (std::isinf(f))
		std::cout << f << "f" << std::endl;
	else
		std::cout << std::fixed
			<< std::setprecision((f == static_cast<int>(f)) ? 1 : 6)
			<< f << "f" << std::endl;

	std::cout << "double: ";
	if (std::isinf(f))
		std::cout << static_cast<double>(f) << std::endl;
	else
		std::cout << std::fixed
			<< std::setprecision((f == static_cast<int>(f)) ? 1 : 6)
			<< static_cast<double>(f) << std::endl;
}

void	print_double(const std::string& str)
{
	double	d = std::strtod(str.c_str(), NULL);

	std::cout << "char: ";
	if (std::isnan(d) || d < 0 || d > 127)
		std::cout << "impossible" << std::endl;
	else if (isprint(static_cast<int>(d)))
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	std::cout << "int: ";
	if (std::isnan(d) || d < MIN_INT || d > MAX_INT)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;

	std::cout << "float: ";
	if (d < -MAX_FLOAT || d > MAX_FLOAT)
		std::cout << "impossible" << std::endl;
	else if (std::isinf(d))
		std::cout << static_cast<float>(d) << "f" << std::endl;
	else
		std::cout << std::fixed
			<< std::setprecision((d == static_cast<int>(d)) ? 1 : 6)
			<< static_cast<float>(d) << "f" << std::endl;

	std::cout << "double: ";
	if (std::isinf(d))
		std::cout << d << std::endl;
	else
		std::cout << std::fixed
			<< std::setprecision((d == static_cast<int>(d)) ? 1 : 6)
			<< d << std::endl;
}