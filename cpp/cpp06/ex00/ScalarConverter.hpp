#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

# include <iostream>
# include <limits>
# include <cmath>
# include <iomanip>
# include <exception>
# include <cstdlib>

# define MIN_INT std::numeric_limits<int>::min()
# define MAX_INT std::numeric_limits<int>::max()
# define MIN_FLOAT std::numeric_limits<float>::min()
# define MAX_FLOAT std::numeric_limits<float>::max()
# define MIN_DOUBLE std::numeric_limits<double>::min()
# define MAX_DOUBLE std::numeric_limits<double>::max()

enum    e_type
{
    SPECIAL = 0,
    CHAR = 1,
    INT = 2,
    FLOAT = 3,
    DOUBLE = 4,
    INVALID = 5
};

e_type  type_specifier(const std::string& str, size_t& len);
void    print_special(const std::string& str);
void	print_char(const std::string& str);
void	print_int(const std::string& str);
void	print_float(const std::string& str);
void	print_double(const std::string& str);

class	ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ~ScalarConverter();

    ScalarConverter& operator=(const ScalarConverter& other);
public:
    static void	convert(const std::string& str);
};

#endif