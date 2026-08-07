/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 15:18:27 by gkankia           #+#    #+#             */
/*   Updated: 2025/11/11 18:31:04 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

void	print_contact(std::string str)
{
	if (str.length() > 10)
		str = str.substr(0, 9) + ".";
	std::cout << "|";
	std::cout << std::setw(10) << str;
}

bool	is_valid_phone_number(const std::string& str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!std::isdigit(str[i]) && str[i] != ' ' && str[i] != '-' && str[i] != '.')
			return false;
		i++;
	}
	return true;
}

void PhoneBook::add_contact(int count_contacts)
{
	Contact		contact;
	std::string	str;

	std::cout << "Enter first name: ";
	std::getline(std::cin >> std::ws, str);
	contact.set_first_name(str);
	
	std::cout << "Enter last name: ";
	std::getline(std::cin >> std::ws, str);
	contact.set_last_name(str);

	std::cout << "Enter nickname: ";
	std::getline(std::cin >> std::ws, str);
	contact.set_nickname(str);

	do
	{
		std::cout << "Enter phone number: ";
		std::getline(std::cin >> std::ws, str);

		if (!is_valid_phone_number(str))
			std::cout << "Invalid input.\n";

	} while (!is_valid_phone_number(str));

	contact.set_phone_number(str);

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin >> std::ws, str);
	contact.set_darkest_secret(str);

	this->contacts[count_contacts] = contact;
}

void	PhoneBook::show_contacts(int count_contact) const
{
	std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
	std::cout << "+----------+----------+----------+----------+\n";
	for (int i = 0; i < count_contact; ++i)
	{
		std::cout << "|" << std::setw(10) << i;
		print_contact(contacts[i].get_first_name());
		print_contact(contacts[i].get_last_name());
		print_contact(contacts[i].get_nickname());
		std::cout << "|\n"; 
	}
	if (count_contact)
		std::cout << "+-------------------------------------------+\n";
	std::cout << "Enter index to view full contact: ";
	int index;
	std::cin >> index;

	if (std::cin.fail() || index < 0 || index >= count_contact)
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Invalid index.\n";
		return;
	}

	std::cout << "First name: " << contacts[index].get_first_name() << "\n";
	std::cout << "Last name: " << contacts[index].get_last_name() << "\n";
	std::cout << "Nickname: " << contacts[index].get_nickname() << "\n";
	std::cout << "Phone number: " << contacts[index].get_phone_number() << "\n";
	std::cout << "Darkest secret: " << contacts[index].get_darkest_secret() << "\n";
}