#include <iostream>
#include "Array.hpp"

// Struct for test "Complex Array Type from own struct"
struct s_test {
	int a;
	char b;
};

int main(int, char**)
{
	Array<int> Array1;
	std::cout << "Array size: " << Array1.size() << std::endl;
	

	try {
		std::cout << "Array[1]: " << Array1[1] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "---------int array---------" << std::endl;
	Array<int> Array2(5);
	int i = 0;
	while (i < 5) {
		Array2[i] = i;
		i++;
	}
	std::cout << "Array size: " << Array2.size() << std::endl;
	std::cout << "Array: ";
	i = 0;
	while (i < 5) {
		std::cout << Array2[i] << " ";
		i++;
	}
	std::cout << std::endl;

	std::cout << "---------string array---------" << std::endl;
	Array<std::string> Array3(3);
	i = 0;
	while (i < 3) {
		Array3[i] = "Hello" + i;
		i++;
	}
	std::cout << "Array size: " << Array3.size() << std::endl;
	std::cout << "Array: ";
	i = 0;
	while (i < 3) {
		std::cout << Array3[i] << " ";
		i++;
	}
	std::cout << std::endl;

	return (0);
}