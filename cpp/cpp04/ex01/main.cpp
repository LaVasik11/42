#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j; // should not create a leak
    delete i;

    j = new Dog();
    i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();

    std::cout << "\n-------------------------------------------\n";

    const WrongAnimal* meta2 = new WrongAnimal();
    const Animal* k = new Dog();
    const WrongAnimal* l = new WrongCat();
    std::cout << k->getType() << " " << std::endl;
    std::cout << l->getType() << " " << std::endl;
    l->makeSound();
    k->makeSound();
    meta2->makeSound();

    delete j;
    delete i;
    delete k;
    delete l;
    delete meta2;

    return 0;
}
