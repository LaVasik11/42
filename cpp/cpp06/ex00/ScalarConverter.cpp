#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { *this = other; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return (*this);
}

void    ScalarConverter::convert(const std::string& str)
{
    size_t  len = str.length();
    e_type  type = type_specifier(str, len);

    switch(type)
    {
        case INVALID:
            std::cout << "Invalid input" << std::endl;
            break;
        case SPECIAL:
            print_special(str);
            break;
        case CHAR:
            print_char(str);
            break;
        case INT:
            print_int(str);
            break;
        case FLOAT:
            print_float(str);
            break;
        case DOUBLE:
            print_double(str);
            break;
    }
}
