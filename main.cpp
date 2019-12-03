#include "AList.h"

int main()
{
	// Testing [] operator.
	AList person;
	person["name"] = "John";
	person["age"] = 32;
	person["male"] = true;
	person["boss"] = new AList();
	person["boss"]["name"] = "Anna";
	person["boss"]["age"] = 41;
	person["boss"]["male"] = false;

	cout << person["name"] << endl;
	cout << person["age"] << endl;
	cout << person["male"] << endl;
	cout << person["boss"]["name"] << endl;
	cout << person["boss"]["age"] << endl;
	cout << person["boss"]["male"] << endl;

	for (int i = 0; i < 10; i++)
	{
		person[i] = i;
	}

	for (int i = 0; i < 10; i++)
	{
		std::cout << person[i] << endl;
	}
	cout << endl;

	// testing order of elements in array.

	for (ItemInfo **it = person.begin() ;it != person.end(); it++)
	{
		if ((*it)->get_name())
			cout << (*it)->get_name() << ": " << (**it) <<endl;
		else
			cout << (*it)->get_index()<< ": " << (**it) <<endl;
	}

    return 0;
}
