#include "bigint.hpp"
#include <sstream>

bigint::bigint() : str("0") {}

bigint::bigint(unsigned int num)
{
	std::stringstream ss;
	ss << num;
	str = ss.str();
}

bigint::bigint(const bigint& source) : str(source.str) {}

std::string bigint::getStr() const
{
	return str;
}

bigint& bigint::operator=(const bigint& source)
{
	if (this != &source)
		str = source.str;
	return *this;
}

static std::string add_strings(const std::string& a, const std::string& b)
{
	std::string res;
	int i = a.size() - 1;
	int j = b.size() - 1;
	int carry = 0;

	while (i >= 0 || j >= 0 || carry)
	{
		int sum = carry;
		if (i >= 0)
			sum += a[i--] - '0';
		if (j >= 0)
			sum += b[j--] - '0';
		res.insert(res.begin(), (sum % 10) + '0');
		carry = sum / 10;
	}
	return res;
}

bigint bigint::operator+(const bigint& other) const
{
	bigint res;
	res.str = add_strings(str, other.str);
	return res;
}

bigint& bigint::operator+=(const bigint& other)
{
	str = add_strings(str, other.str);
	return *this;
}

bigint& bigint::operator++()
{
	*this += bigint(1);
	return *this;
}

bigint bigint::operator++(int)
{
	bigint tmp(*this);
	*this += bigint(1);
	return tmp;
}

bigint bigint::operator<<(unsigned int n) const
{
	bigint res(*this);
	if (res.str != "0")
		res.str.append(n, '0');
	return res;
}

bigint bigint::operator>>(unsigned int n) const
{
	bigint res(*this);
	if (n >= res.str.size())
		res.str = "0";
	else
		res.str.erase(res.str.size() - n);
	return res;
}

bigint& bigint::operator<<=(unsigned int n)
{
	if (str != "0")
		str.append(n, '0');
	return *this;
}

bigint& bigint::operator>>=(unsigned int n)
{
	if (n >= str.size())
		str = "0";
	else
		str.erase(str.size() - n);
	return *this;
}

static unsigned int to_uint(const std::string& s)
{
	unsigned int res = 0;
	for (size_t i = 0; i < s.size(); i++)
		res = res * 10 + (s[i] - '0');
	return res;
}

bigint bigint::operator<<(const bigint& other) const
{
	return *this << to_uint(other.str);
}

bigint bigint::operator>>(const bigint& other) const
{
	return *this >> to_uint(other.str);
}

bigint& bigint::operator<<=(const bigint& other)
{
	return *this <<= to_uint(other.str);
}

bigint& bigint::operator>>=(const bigint& other)
{
	return *this >>= to_uint(other.str);
}

bool bigint::operator==(const bigint& other) const
{
	return str == other.str;
}

bool bigint::operator!=(const bigint& other) const
{
	return str != other.str;
}

bool bigint::operator<(const bigint& other) const
{
	if (str.size() != other.str.size())
		return str.size() < other.str.size();
	return str < other.str;
}

bool bigint::operator>(const bigint& other) const
{
	return other < *this;
}

bool bigint::operator<=(const bigint& other) const
{
	return !(other < *this);
}

bool bigint::operator>=(const bigint& other) const
{
	return !(*this < other);
}

std::ostream& operator<<(std::ostream& output, const bigint& obj)
{
	output << obj.getStr();
	return output;
}
