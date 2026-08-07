#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
# include <sstream>
# include <exception>

class RPN
{
public:
	RPN();
	RPN(const std::string& str);
	RPN(const RPN& other);
	~RPN();

	RPN& operator=(const RPN& other);

	void	execute(const std::string& str);
	void	execute_part(const std::string& op);
	int		get_result() const;

	class RpnSyntaxError : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return ("Error");
		}
	};
private:
	std::stack<int>	stack;
	
	bool	is_valid(const std::string& str);
	int		calculate(int a, int b, const std::string& op);
	int		plus(int a, int b);
	int		minus(int a, int b);
	int		multiply(int a, int b);
	int		divide(int a, int b);
};

#endif