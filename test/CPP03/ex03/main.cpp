// Created by tde-sous on 14-01-2024.

#include "DiamondTrap.hpp"
#include <iostream>
#include <stdio.h>

int main() {
  std::cout << "\n-----------------------------------------\n";

    DiamondTrap diamond("diamond");
    printf("DiamondTrap name: %s\n", diamond.getName().c_str());
    printf("DiamondTrap hit points: %d\n", diamond.getHitPoints());
    printf("DiamondTrap energy points: %d\n", diamond.getEnergyPoints());
    printf("DiamondTrap attack damage: %d\n", diamond.getAttackDamage());

    diamond.whoAmI();
    return (0);
}