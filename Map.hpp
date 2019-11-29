#include <iostream>
#include <map>

typedef unsigned int uint;

template<typename K, typename V>
class Map
{
struct data
{
	K key;
	V value;
};

private:
	data	*arr;
	uint	size;
	uint	capacity;

public:
	Map();
	~Map();
	Map(const Map& rhs);
	Map &operator=(const Map &rhs);

};


int main()
{

	std::cout << "Hello, World!" << std::endl;
	return 0;
}
