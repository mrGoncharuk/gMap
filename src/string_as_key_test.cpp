//
// Created by mhonchar on 30.11.19.
//

//
// Created by mhonchar on 30.11.19.
//

#include <iostream>
#include "../includes/Map.hpp"
#include <string>
#include <map>

static bool	test1()
{
	std::cout << "------Test1--------\n Ascending order insertion\n";
	std::map<std::string, int> sm;
	Map<std::string, int> m;
	std::string values = "";

	for (int i = -10; i < 10; i++)
	{
		values += 'a';
		sm.insert(std::pair<std::string, int>(values, i));
		m.insert(values, i);
	}
	if (m.size() != sm.size())
		return false;
	std::map<std::string, int>::iterator sit = sm.begin();
	Map<std::string, int>::pair *it = m.begin();
	while (sit != sm.end())
	{
		if (sit->first != it->key || sit->second != it->value)
			return false;
		sit++;
		it++;
	}

	return true;
}

static bool	test2()
{
	std::cout << "------Test2--------\n Descending order insertion\n";
	std::map<std::string, int> sm;
	Map<std::string, int> m;
	std::string values = "";

	for (int i = 10; i > -10; i--)
	{
		values += 'a';
		sm.insert(std::pair<std::string, int>(values, i));
		m.insert(values, i);
	}
	if (m.size() != sm.size())
		return false;
	std::map<std::string, int>::iterator sit = sm.begin();
	Map<std::string, int>::pair *it = m.begin();
	while (sit != sm.end())
	{
		if (sit->first != it->key || sit->second != it->value)
			return false;
		sit++;
		it++;
	}
	return true;
}

static bool	test3()
{
	std::cout << "------Test3--------\n Insertion without order and existing keys\n";
	std::map<std::string, int> sm;
	Map<std::string, int> m;
	std::string values = "";

	for (int i = -10; i < 10; i+=2)
	{
		values += 'a';
		sm.insert(std::pair<std::string, int>(values, i));
		m.insert(values, i);
	}
	if (m.size() != sm.size())
		return false;
	for (int i = -10; i < 10; i++)
	{
		values += 'a';
		sm.insert(std::pair<std::string, int>(values, i));
		m.insert(values, i);
	}
	if (m.size() != sm.size())
		return false;
	std::map<std::string, int>::iterator sit = sm.begin();
	Map<std::string, int>::pair *it = m.begin();
	while (sit != sm.end())
	{
		if (sit->first != it->key || sit->second != it->value)
			return false;
		sit++;
		it++;
	}
	return true;
}


static bool	test4()
{
	std::cout << "------Test4--------\n Erase test\n";
	std::map<std::string, int> sm;
	Map<std::string, int> m;
	std::string values = "";

	for (int i = -10; i < 10; i++)
	{
		values += 'a';
		sm.insert(std::pair<std::string, int>(values, i));
		m.insert(values, i);
	}
	values = "";
	for (int i = -20; i < 10; i+=3)
	{
		values += 'a';
		if (sm.erase(values) != m.erase(values))
			return false;
	}
	if (m.size() != sm.size())
		return false;
	std::map<std::string, int>::iterator sit = sm.begin();
	Map<std::string, int>::pair *it = m.begin();
	while (sit != sm.end())
	{
		if (sit->first != it->key || sit->second != it->value)
			return false;
		sit++;
		it++;
	}
	values = "";
	for (int i = -10; i < 10; i++)
	{
		values += 'a';
		if (sm.erase(values) != m.erase(values))
			return false;
	}
	return m.size() == sm.size();
}

static bool	test5()
{
	std::cout << "------Test5--------\n Clear test\n";
	std::map<std::string, int> sm;
	Map<std::string, int> m;
	std::string values = "";

	for (int i = -10; i < 10; i++)
	{
		values += 'a';
		sm.insert(std::pair<std::string, int>(values, i));
		m.insert(values, i);
	}
	m.clear();
	sm.clear();
	if (m.size() != sm.size())
		return false;
	for (int i = 0; i < 5; i++)
	{
		values += 'a';
		sm.insert(std::pair<std::string, int>(values, i));
		m.insert(values, i);
	}
	if (m.size() != sm.size())
		return false;
	std::map<std::string, int>::iterator sit = sm.begin();
	Map<std::string, int>::pair *it = m.begin();
	while (sit != sm.end())
	{
		if (sit->first != it->key || sit->second != it->value)
			return false;
		sit++;
		it++;
	}
	return true;
}

static bool	test6()
{
	std::cout << "------Test6--------\n Swap test\n";
	std::map<std::string, int> sm, sm2;
	Map<std::string, int> m, m2;
	std::string values = "";

	for (int i = -10; i < 10; i++)
	{
		values += 'a';
		sm.insert(std::pair<std::string, int>(values, i));
		m.insert(values, i);
	}
	for (int i = 15; i < 20; i++)
	{
		values += 'b';
		sm2.insert(std::pair<std::string, int>(values, i));
		m2.insert(values, i);
	}
	m.swap(m2);
	sm.swap(sm2);
	if (m.size() != sm.size() || m2.size() != sm2.size())
		return false;
	std::map<std::string, int>::iterator sit = sm.begin();
	Map<std::string, int>::pair *it = m.begin();
	while (sit != sm.end())
	{
		if (sit->first != it->key || sit->second != it->value)
			return false;
		sit++;
		it++;
	}
	sit = sm2.begin();
	it = m2.begin();
	while (sit != sm2.end())
	{
		if (sit->first != it->key || sit->second != it->value)
			return false;
		sit++;
		it++;
	}
	return true;
}

static bool	test7()
{
	std::cout << "------Test7--------\n Array element access[] operator test\n";
	std::map<std::string, int> sm;
	Map<std::string, int> m;
	std::string values;

	for (int i = -10; i < 10; i+=2)
	{
		values += 'a';
		sm[values] = i;
		m[values] = i;
	}
	if (m.size() != sm.size())
		return false;
	for (int i = -10; i < 10; i++)
	{
		values += 'a';
		sm[values] = i;
		m[values] = i;
	}
	if (m.size() != sm.size())
		return false;
	std::map<std::string, int>::iterator sit = sm.begin();
	Map<std::string, int>::pair *it = m.begin();
	while (sit != sm.end())
	{
		if (sit->first != it->key || sit->second != it->value)
			return false;
		sit++;
		it++;
	}
	values = "b";
	for (int i = -10; i < 10; i++)
	{
		sm[values] = i;
		m[values] = i;
		values += 'b';
	}
	sit = sm.begin();
	it = m.begin();
	while (sit != sm.end())
	{
		if (sit->first != it->key || sit->second != it->value)
			return false;
		sit++;
		it++;
	}
	return true;
}

static bool	test8()
{
	std::cout << "------Test8--------\n Copy constructor test\n";
	std::map<std::string, int> sm;
	Map<std::string, int> m;
	std::string values = "";

	for (int i = -10; i < 10; i++)
	{
		values += 'a';
		sm.insert(std::pair<std::string, int>(values, i));
		m.insert(values, i);
	}
	std::map<std::string, int> sm_cpy(sm);
	Map<std::string, int> m_cpy(m);
	if (m_cpy.size() != sm_cpy.size())
		return false;
	std::map<std::string, int>::iterator sit = sm_cpy.begin();
	Map<std::string, int>::pair *it = m_cpy.begin();
	while (sit != sm_cpy.end())
	{
		if (sit->first != it->key || sit->second != it->value)
			return false;
		sit++;
		it++;
	}
	return true;
}

static bool	test9()
{
	std::cout << "------Test8--------\n Copy constructor test\n";
	std::map<std::string, int> sm;
	Map<std::string, int> m;
	std::string values = "";

	for (int i = -10; i < 10; i++)
	{
		values += 'a';
		sm.insert(std::pair<std::string, int>(values, i));
		m.insert(values, i);
	}
	std::map<std::string, int> sm_cpy = sm;
	Map<std::string, int> m_cpy = m;
	if (m_cpy.size() != sm_cpy.size())
		return false;
	std::map<std::string, int>::iterator sit = sm_cpy.begin();
	Map<std::string, int>::pair *it = m_cpy.begin();
	while (sit != sm_cpy.end())
	{
		if (sit->first != it->key || sit->second != it->value)
			return false;
		sit++;
		it++;
	}

	return true;
}

int run_string_as_key_test()
{
	int passed = 0;

	std::cout << "---------------------String as key tests---------------------\n";
	if (test1() == false)
		std::cout << "KO. Test1: Ascending order insertion\n\n";
	else
	{
		passed++;
		std::cout << "OK. Test1\n\n";
	}
	if (test2() == false)
		std::cout << "KO. Test2: Descending order insertion\n\n";
	else
	{
		passed++;
		std::cout << "OK. Test2\n\n";
	}
	if (test3() == false)
		std::cout << "KO. Test3: Insertion without order and with existing keys\n\n";
	else
	{
		passed++;
		std::cout << "OK. Test4\n\n";
	}
	if (test4() == false)
		std::cout << "KO. Test4: Erasing test\n\n";
	else
	{
		passed++;
		std::cout << "OK. Test4\n\n";
	}
	if (test5() == false)
		std::cout << "KO. Test5: Clearing test\n\n";
	else
	{
		passed++;
		std::cout << "OK. Test5\n\n";
	}
	if (test6() == false)
		std::cout << "KO. Test6: Swap test\n\n";
	else
	{
		passed++;
		std::cout << "OK. Test6\n\n";
	}
	if (test7() == false)
		std::cout << "KO. Test7: Array element access[] operator\n\n";
	else
	{
		passed++;
		std::cout << "OK. Test7\n\n";
	}
	if (test8() == false)
		std::cout << "KO. Test8: Copy constructor test\n\n";
	else
	{
		passed++;
		std::cout << "OK. Test8\n\n";
	}
	if (test9() == false)
		std::cout << "KO. Test9:  Assignment operator test\n\n";
	else
	{
		passed++;
		std::cout << "OK. Test9:  Assignment operator test\n\n";
	}
	return (passed);
}
