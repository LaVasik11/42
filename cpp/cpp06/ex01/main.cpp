#include "Serializer.hpp"

int main(void)
{

	Data *data = new Data;
	data->d = 42;
	data->f = 42.42;
	data->c = 'a';
    data->str = "|string|";

	uintptr_t raw = Serializer::serialize(data);
	Data *serialized = Serializer::deserialize(raw);

	std::cout << serialized->d << std::endl;
	std::cout << serialized->f << std::endl;
	std::cout << serialized->c << std::endl;
    std::cout << serialized->str << std::endl;

	delete data;
	return (0);
}