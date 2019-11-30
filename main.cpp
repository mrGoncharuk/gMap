#include <iostream>
#include "Map.hpp"
#include <string>
#include <map>
typedef unsigned int uint;

void	test1()
{
	std::cout << "------Test1--------\n Ascending order insertion\n";
	Map<int, std::string> m;
	for (int i = 0; i < 10; i++)
	{
		m.insert(i, "Kek");
	}
	m.show();
	std::cout << "\n\n";
}

void	test2()
{
	std::cout << "------Test2--------\n Descending order insertion\n";
	Map<int, std::string> m;
	for (int i = 10; i > 0; i--)
	{
		m.insert(i, "Kek");
	}
	m.show();
	std::cout << "\n\n";
}

void	test3()
{
	std::cout << "------Test3--------\n Insertion with negative keys\n";
	Map<int, std::string> m;
	for (int i = -10; i < 10; i++)
	{
		m.insert(i, "Kek");
	}
	m.show();
	std::cout << "\n\n";
}

void	test4()
{
	std::cout << "------Test4--------\n Odd and even insertion with negative keys\n";
	Map<int, std::string> m;
	for (int i = -10; i < 10; i+=2)
	{
		m.insert(i, "Kek");
	}
	for (int i = -10; i < 10; i++)
	{
		m.insert(i, "Kek");
	}
	m.show();
	std::cout << "\n\n";
}


void	test5()
{
	std::cout << "------Test5--------\n Erase test\n";
	Map<int, std::string> m;
	for (int i = 0; i < 10; i++)
	{
		m.insert(i, "Kek");
	}
	m.erase(5);
	m.erase(0);
	m.erase(9);
	m.erase(5);
	m.erase(0);
	m.erase(9);
	m.show();
	std::cout << "\n\n";
}

void	test6()
{
	std::cout << "------Test6--------\n Erase test on limiting values\n";
	Map<int, std::string> m;
	for (int i = 0; i < 1; i++)
	{
		m.insert(i, "Kek");
	}
	std::cout << "Erasing values that doesn't exist\n";
	m.erase(1);
	m.erase(2);
	m.erase(-1);
	m.show();
	std::cout << "Erasing just one value that exist\n";
	m.erase(0);
	m.show();
	std::cout << "Trying to insert value(k = 5; val = 'Kek' to map where values where erased\n";
	m.insert(5, "Kek");
	m.show();
	std::cout << "\n\n";
}

void	test7()
{
	std::cout << "------Test7--------\n Clear test\n";
	Map<int, std::string> m;
	for (int i = 0; i < 10; i++)
	{
		m.insert(i, "Kek");
	}
	m.clear();
	m.show();
	for (int i = 0; i < 10; i++)
	{
		m.insert(i, "Kek");
	}
	m.show();
	std::cout << "\n\n";
}

void	test8()
{
	std::cout << "------Test8--------\n Swap test\n";
	Map<int, std::string> m;

	for (int i = 1; i < 5; i++)
	{
		m.insert(i, "Kek");
	}
	Map<int, std::string> m1;
	for (int i = 8; i < 10; i++)
	{
		m1.insert(i, "Kek");
	}
	m.show();
	m1.show();
	m.swap(m1);
	m.show();
	m1.show();
	std::cout << "\n\n";
}

void	test9()
{
	std::cout << "------Test9--------\n [] operator test\n";
	Map<int, std::string> m;

	for (int i = 0; i < 5; i++)
		m[i] = "kek";
	m.show();
}

//void	test10()
//{
//	std::cout << "------Test10--------\n Begin() end() test operator test\n";
//	Map<int, std::string> m;
//
//	for (int i = 0; i < 15; i++)
//		m[i] = "kek";
//
//	for (pair<int, std::string> *it = m.begin(); it < m.end(); it++)
//	{
//		std::cout << "Key: " << it->key << " Value: " << it->value << std::endl;
//	}
//}

int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
//	test10();
	return 0;
}
