/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:47:01 by gkankia           #+#    #+#             */
/*   Updated: 2025/07/08 17:47:02 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

typedef std::string str;

class Zombie {
	public:
		Zombie();
		~Zombie();

		void	setName(str name);
		void	announce() const;

	private:
		str	name;
};

Zombie	*zombieHorde(int n, str name);

#endif