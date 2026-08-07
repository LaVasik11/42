/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:47:07 by gkankia           #+#    #+#             */
/*   Updated: 2026/03/17 18:31:00 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int	n = 5;
	Zombie	*horde = zombieHorde(n, "Bob");
	for (int i = 0; i < n; i++)
		horde[i].announce();
	delete[] horde;
	return 0;
}