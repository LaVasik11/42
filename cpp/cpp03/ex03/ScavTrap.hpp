/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy-kankiya <georgy-kankiya@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:22:48 by gkankia           #+#    #+#             */
/*   Updated: 2025/08/27 14:35:02 by georgy-kank      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap 
{
	public:
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &src);
		ScavTrap();
		~ScavTrap();

		ScavTrap & operator=(ScavTrap const &src);
		
		void	attack(const std::string &target);
		void	guardGate();
	private:
};

#endif