/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 17:19:37 by gkankia           #+#    #+#             */
/*   Updated: 2025/07/12 17:19:38 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

typedef std::string str;

void	ft_replace(str &line, str s1, str s2) 
{
	size_t	startPos = 0;

	while ((startPos = line.find(s1, startPos)) != str::npos) 
	{
		line = line.substr(0, startPos) + s2 + line.substr(startPos + s1.length());
		startPos += s2.length();
	}
}

int	main(int ac, char **av) 
{
	if (ac != 4)
	{
		std::cout << "Error\n";
		return (0);
	}
	
	str				file = av[1];
	str				s1 = av[2];
	str				s2 = av[3];
	str				line;
	str				out_file = file + ".replace";
	std::ifstream	input(file.c_str());
	std::ofstream	output(out_file.c_str());
	
	if (input.is_open())
	{
		while (std::getline(input, line))
		{
			ft_replace(line, s1, s2);
			output << line;
			if (!input.eof())
				output << std::endl;
		}
		input.close();
		output.close();
	}
	else
		std::cout << "Error\n" << std::endl;
	return (0);
}