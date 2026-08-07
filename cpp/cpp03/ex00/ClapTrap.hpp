/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy-kankiya <georgy-kankiya@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:02:51 by gkankia           #+#    #+#             */
/*   Updated: 2025/08/27 14:35:02 by georgy-kank      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include "iostream"

class ClapTrap
{
    public:
        ClapTrap(std::string name);
        ClapTrap();
		~ClapTrap();
		ClapTrap(ClapTrap const &src);
		ClapTrap&	operator=(ClapTrap const &src);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string getName() const;
        int         getHitPoints() const;
		int		    getEnergyPoints() const;
		int		    getAttackDamage() const;
        void        setName(std::string name);
		void	    setHitPoints(int hp);
		void        setEnergyPoints(int ep);
		void	    setAttackDamage(int damage);
        
    private:
        std::string name;
        int         hp;
        int         ep;
        int         damage;
};

#endif