/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:47:27 by gkankia           #+#    #+#             */
/*   Updated: 2025/07/08 17:47:28 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) 
{
	std::cout << this->name << " is born" << std::endl;
}

Zombie::~Zombie() 
{
	std::cout << this->name << " is destroyed" << std::endl;
}

void Zombie::announce() 
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}