#include "ScalarConverter.hpp"

static int	isSpecial(const std::string& str)
{
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
		return (1);
	return (0);
}

static int	isChar(const std::string& str, size_t& len)
{
	if (len == 1 && !isdigit(str[0]))
		return (1);
	if (len == 3 && str[0] == '\'' && str[2] == '\'')
		return (1);
	return (0);
}

static int	isInt(const std::string& str, size_t& len)
{
	int		i = 0;
	bool	flag = false;

	if (str[0] == '-' || str[0] == '+')
	{
		i++;
		flag = 1;
	}
	while ((str[i] && len > 0 && len < 12) || (str[i] && !flag && len > 0 && len < 11))
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

bool	isFloat(const std::string& str, size_t& len, size_t dot)
{
	size_t	i;

	i = 0;
	len = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (i == str.length())
		return (false);
	if (dot == 0 || dot >= str.length() - 2)
		return (false);
	if (str[str.length() - 1] != 'f')
		return (false);
	while (i < str.length() - 1)
	{
		if (i == dot)
		{
			i++;
			continue ;
		}
		if (!std::isdigit(str[i]))
			return (false);
		i++;
	}
	len = i + 1;
	return (true);
}

bool	isDouble(const std::string& str, size_t& len, size_t dot)
{
	size_t	i;

	i = 0;
	len = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (i == str.length())
		return (false);
	if (dot == 0 || dot == str.length() - 1)
		return (false);
	while (i < str.length())
	{
		if (i == dot)
		{
			i++;
			continue ;
		}
		if (!std::isdigit(str[i]))
			return (false);
		i++;
	}
	len = i;
	return (true);
}

e_type  type_specifier(const std::string& str, size_t& len)
{
	size_t	dot = str.find('.');
	size_t	fl = str.find('f');

	if (dot == std::string::npos)
		{
		if (isSpecial(str))
			return (SPECIAL);
		if (isChar(str, len))
			return (CHAR);
		if (isInt(str, len))
			return (INT);
	}
	if (fl != std::string::npos && dot != std::string::npos)
	{
		if (isFloat(str, len, dot))
			return (FLOAT);
	}
	else if (fl == std::string::npos && dot != std::string::npos)
	{
		if (isDouble(str, len, dot))
			return (DOUBLE);
	}
	return (INVALID);
}