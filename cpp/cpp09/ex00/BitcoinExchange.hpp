#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include "iostream"
#include <map>
#include <fstream>
#include <exception>
#include <string>
#include <sstream>

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange();

	BitcoinExchange& operator=(const BitcoinExchange& other);

	void execute(const char* filename);

	class OpenFileError : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return ("Open file error.");
		}
	};

	class InvalidFile : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return ("Invalid file");
		}
	};
private:
	std::map<std::string, double>	exchange_rate;
	void							parse_db();
	void 							multiplyWithQuote(const std::string& date, double price);
	bool							validate_date(const std::string& date);
	double							validate_price(const std::string& price);
	std::string						trim(const std::string& str);
};

#endif