#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	parse_db();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		exchange_rate = other.exchange_rate;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::trim(const std::string& str)
{
    size_t	start;

	start = str.find_first_not_of(" \t\n\r\f\v");
    if (start == std::string::npos)
        return "";
    size_t end = str.find_last_not_of(" \t\n\r\f\v");
    return str.substr(start, end - start + 1);
}

void BitcoinExchange::execute(const char *filename)
{
	std::ifstream	file(filename);
	if (!file.is_open())
		throw OpenFileError();

	std::string	line;
	std::getline(file, line);
	if (line != "date | value")
		throw InvalidFile();
	
	while (std::getline(file, line))
	{
		std::string			date;
		std::string			value;
		double				price;
		std::istringstream	ss(line);

		std::getline(ss, date, '|');
		std::getline(ss, value, '|');

		if (!date.empty())
			date = trim(date);
		if (validate_date(date) == false)
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		if(!value.empty())
			value = trim(value);
		price = validate_price(value);
		if (price != -1)
			multiplyWithQuote(date, price);
	}
}

void BitcoinExchange::multiplyWithQuote(std::string const &date, double price)
{
	std::map<std::string, double>::iterator it = exchange_rate.find(date);
	if (it != exchange_rate.end())
		std::cout << date << " => " << price << " = " << price * it->second << std::endl;
	else
	{
		std::map<std::string, double>::iterator it2 = exchange_rate.lower_bound(date);
		if (it2 == exchange_rate.begin())
			std::cout << date << " => " << price << " = " << price * it2->second << std::endl;
		else
		{
			it2--;
			std::cout << date << " => " << price << " = " << price * it2->second << std::endl;
		}
	}
}

double	BitcoinExchange::validate_price(const std::string& price)
{
	double priceValue;
	std::istringstream priceStream(price);

	if (!(priceStream >> priceValue))
	{
		std::cout << "Error: bad value input." << std::endl;
		return (-1);
	}

	if (priceValue < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (-1);
	}
	else if (priceValue > 1000)
	{
		std::cout << "Error: too large number." << std::endl;
		return (-1);
	}
	
	return (priceValue);
}

bool	BitcoinExchange::validate_date(const std::string& date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);

	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return (false);
	}

	int y = std::stoi(date.substr(0, 4));
	int m = std::stoi(date.substr(5, 2));
	int d = std::stoi(date.substr(8, 2));

	if (m < 1 || m > 12 || d < 1)
		return (false);

	int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
		days[1] = 29;

	if (d > days[m - 1])
		return (false);

	return (true);
}

void BitcoinExchange::parse_db()
{
	std::ifstream	file("data.csv");
	if (!file.is_open())
		throw OpenFileError();

	std::string	line;

	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::string			date;
		std::string			price;
		std::istringstream	ss(line);
		double				price_value;

		std::getline(ss, date, ',');
		std::getline(ss, price);
		price_value = std::atof(price.c_str());
		exchange_rate[date] = price_value;
	}
}