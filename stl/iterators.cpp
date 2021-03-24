#include <iostream>
#include <vector>
#include<unordered_map>

int main()
{
	std::vector<int> values{1, 2, 3, 4, 5};

	// for(int value : values) 
	// 	std::cout << value << std::endl;

	// for(std::vector<int>::iterator it = values.begin(); it != values.end(); it++) 
	// 	std::cout << *it << std::endl;

	using ScoreMap = std::unordered_map<std::string, int>;
	ScoreMap map;
	map["Cherno"] = 5;
	map["Cpp"] = 2;

	for(ScoreMap::const_iterator it = map.begin(); it != map.end(); it++)
	{
		auto& key = it->first;
		auto& val = it->second;
		std::cout << key << " = " << val << std::endl;
	}

	std::cout << std::endl;

	for(auto kv : map)
	{
		auto& key = kv.first;
		auto& val = kv.second;
		std::cout << key << " = " << val << std::endl;
	}

	std::cout << std::endl;

	// From cpp 17 onwards
	for(auto [key, value] : map)
		std::cout << key << " = " << value << std::endl;

	return 0;
}
