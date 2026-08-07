/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:09:52 by gkankia           #+#    #+#             */
/*   Updated: 2025/08/05 16:46:37 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap    hero("Name1");

    hero.setAttackDamage(2);

    hero.attack("enemy1");
    hero.takeDamage(3);
    hero.beRepaired(1);
    hero.beRepaired(1);
    hero.attack("enemy2");
    hero.takeDamage(5);
    hero.attack("enemy2");
    hero.takeDamage(7);
    hero.attack("enemy2");
    return (0);
}