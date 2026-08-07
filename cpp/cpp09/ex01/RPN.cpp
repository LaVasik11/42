#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const std::string &str)
{
	if (!is_valid(str))
		throw RpnSyntaxError();

	execute(str);
}

RPN::RPN(const RPN& other)
{
	*this = other;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		stack = other.stack;
	return (*this);
}

RPN::~RPN() {}

void RPN::execute(const std::string& str)
{
	std::stringstream	ss(str);
	std::string			part;
	int					num;

	while (std::getline(ss, part, ' '))
	{
		if ((part.length() == 1 && isdigit(part[0])) || (part.length() == 2 && part[0] == '-' && isdigit(part[1])))
		{
			std::stringstream(part) >> num;
			stack.push(num);
		}
		else
		{
			execute_part(part);
		}
	}
}

void RPN::execute_part(const std::string& op)
{
	int	a;
	int	b;

	if (stack.size() < 2)
		throw RpnSyntaxError();

	b = stack.top();
	stack.pop();
	a = stack.top();
	stack.pop();
	stack.push(calculate(a, b, op));
}

int	RPN::calculate(int a, int b, const std::string& op)
{
	if (op == "+")
		return (a + b);
	if (op == "-")
		return (a - b);
	if (op == "*")
		return (a * b);
	if (op == "/")
		return (a / b);
	return (0);
}

bool RPN::is_valid(const std::string& str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i])
			&& str[i] != '+'
			&& str[i] != '-'
			&& str[i] != '*'
			&& str[i] != '/'
			&& str[i] != ' ')
			return (false);
	}
	return (true);
}

int	RPN::get_result() const
{
	if (stack.empty())
		throw RpnSyntaxError();
	else if (stack.size() > 1)
		throw RpnSyntaxError();

	return (stack.top());
}