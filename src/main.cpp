#include <iostream>
#include "../includes/Map.hpp"
#include "../includes/test_functions.hpp"

int main()
{
	int int_test = run_int_as_key_test();
	int str_test = run_string_as_key_test();
	int nest_test = run_nested_map_test();
	std::cout << "--------Summary----------\n";
	std::cout << "Int as key tests totally passed: " << int_test << "/10.\n";
	std::cout << "String as key tests totally passed: " << str_test << "/9.\n";
	std::cout << "Nested arrays tests totally passed: " << nest_test << "/1.\n";
	return 0;
}
