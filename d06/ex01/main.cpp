#include <iostream>
#include <cstdlib>
#include <string>

struct Data
{
        std::string s1;
        int n;
        std::string s2;
};

void * serialize( void )
{
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	char	*data = new char[22];
	int		n = std::rand();

	std::cout << "Serialized values: " << std::endl;
	for(int i = 0; i < 8; i++)
	{
        data[i] = alphanum[std::rand() % 61];
		std::cout << data[i];
	}
	*(reinterpret_cast<int *>(&data[8])) = n;
	std::cout << n;
	for(int i = 0; i < 8; i++)
	{
        data[i + 12] = alphanum[std::rand() % 61];
		std::cout << data[i + 12];
	}
	std::cout << std::endl;

	return (reinterpret_cast<void*>(data));
}

Data    *deserialize(void       *raw)
{
	Data * d = new Data;

	d->s1.assign(reinterpret_cast<char *>(raw), 8);
	d->n = *reinterpret_cast<int *>(&reinterpret_cast<char *>(raw)[8]);
	d->s2.assign(&reinterpret_cast<char *>(raw)[12], 8);
	return d;
}

int		main(void)
{
	std::srand(std::time(0));
	void	*serial;
	Data	*data;

	serial = serialize();
	data = deserialize(serial);

	std::cout << "Deserialized values:" << std::endl;

	std::cout << "s1\t" << data->s1 << std::endl;
	std::cout << "n\t"  << data->n  << std::endl;
	std::cout << "s2\t" << data->s2 << std::endl;
	delete data;
	return (0);
}


