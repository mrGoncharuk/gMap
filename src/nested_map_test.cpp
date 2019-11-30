//
// Created by mhonchar on 30.11.19.
//

#include <iostream>
#include "../includes/Map.hpp"
#include <string>
#include <map>

typedef std::map< int, int > stdMapInts;
typedef std::map< std::string, stdMapInts > stdMapStrInts;

typedef Map< int, int > MapInts;
typedef Map< std::string, MapInts > MapStrInts;

static bool	test1()
{
	std::cout << "------Test--------\n Nested associative array test.\n";
	stdMapStrInts sm;
	MapStrInts m;
	std::string keys[] = {"one", "two", "three", "four", "five"};
	int start = 0;
	for (int i = 0; i < 5; i++)
	{
		stdMapInts smi;
		MapInts mi;
		for (int j = start; j < start + 5; j++)
		{
			smi[j] = j;
			mi[j] = j;
		}
		m[keys[i]] = mi;
		sm[keys[i]] = smi;
		start += 5;
	}

	stdMapStrInts::iterator sit = sm.begin();
	MapStrInts::pair *it = m.begin();
	if (m.size() != sm.size())
		return false;
	while (sit != sm.end())
	{
		if (sit->first != it->key)
			return false;
		stdMapInts::iterator std_ints_it = sit->second.begin();
		MapInts::pair *ints_it = it->value.begin();
		while (std_ints_it != sit->second.end())
		{
			if (std_ints_it->first != ints_it->key || std_ints_it->second != ints_it->value)
				return false;
			std_ints_it++;
			ints_it++;
		}
		sit++;
		it++;
	}
	return true;
}


int run_nested_map_test()
{
	int passed = 0;
	if (test1() == false)
		std::cout << "KO. Test: nested associative array test.\n\n";
	else
	{
		passed++;
		std::cout << "OK. Test\n\n";
	}
	return passed;
}
