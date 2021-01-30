#include <iostream>
#include <tuple>

std::tuple<std::string, int> CreatePerson()
{
	return {"Cherno", 24};
}

// ver1

void ver1a()
{	
	std::tuple<std::string, int> person = CreatePerson();
	std::string& name = std::get<0>(person);
	int age = std::get<1>(person);
	std::cout << "Name: " << name << " Age: " << age << std::endl;
}

void ver1b()
{	
	auto person = CreatePerson();
	auto name   = std::get<0>(person);
	auto age    = std::get<1>(person);
	std::cout << "Name: " << name << " Age: " << age << std::endl;
}

// ver2

void ver2()
{
	std::string name;
	int age;
	std::tie(name, age) = CreatePerson();
	std::cout << "Name: " << name << " Age: " << age << std::endl;
}

// ver3

struct Person
{
	std::string Name;
	int Age;
};

Person CreatePerson_ver3()
{
	return {"Cherno", 24};
}

void ver3()
{
	Person p = CreatePerson_ver3();
	std::cout << "Name: " << p.Name << " Age: " << p.Age << std::endl;
}

// ver4 from C++17

void ver4a()
{
	auto [name, age] =  CreatePerson();
	std::cout << "Name: " << name << " Age: " << age << std::endl;

}


int main()
{
	ver4b();

	return 0;
}
