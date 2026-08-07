/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy-kankiya <georgy-kankiya@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:07:51 by gkankia           #+#    #+#             */
/*   Updated: 2025/08/27 14:35:02 by georgy-kank      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const &src);
		Fixed&	operator=(Fixed const &src);
		Fixed(const int n);
		Fixed(const float f);

		Fixed			operator+(Fixed const &src) const;
		Fixed			operator-(Fixed const &src) const;
		Fixed			operator*(Fixed const &src) const;
		Fixed			operator/(Fixed const &src) const;
		bool			operator<(Fixed const &src) const;
		bool			operator>(Fixed const &src) const;
		bool			operator<=(Fixed const &src) const;
		bool			operator>=(Fixed const &src) const;
		bool			operator==(Fixed const &src) const;
		bool			operator!=(Fixed const &src) const;
		Fixed&			operator++();
		Fixed			operator++(int);
		Fixed&			operator--();
		Fixed			operator--(int);

		static Fixed &			min(Fixed &a, Fixed &b);
		static Fixed &			max(Fixed &a, Fixed &b);
		static Fixed const &	min(Fixed const &a, Fixed const &b);
		static Fixed const &	max(Fixed const &a, Fixed const &b);

		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;

	private:
		int					value;
		static const int	bits = 8;
};

std::ostream&	operator<<(std::ostream& o, Fixed const &src);

#endif