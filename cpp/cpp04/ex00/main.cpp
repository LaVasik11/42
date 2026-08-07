#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta1 = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta1->makeSound();
    std::cout << "\n-------------------------------------------\n";
    const WrongAnimal* meta2 = new WrongAnimal();
    const Animal* k = new Dog();
    const WrongAnimal* l = new WrongCat();
    std::cout << k->getType() << " " << std::endl;
    std::cout << l->getType() << " " << std::endl;
    l->makeSound(); //will output the cat sound!
    k->makeSound();
    meta2->makeSound();
    delete meta1;
    delete j;
    delete i;
    delete meta2;
    delete k;
    delete l;
    return 0;
}