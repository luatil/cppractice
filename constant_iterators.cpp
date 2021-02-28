#include <iostream>
#include <vector>

void ex1()
{
	std::vector<int> v{1, 2, 3, 4};
	std::vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
}

void ex2()
{
	std::vector<int> v{1, 2, 3, 4};
	std::vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); ++it)
	{
		*it *= 2;
		std::cout << *it << std::endl;
	}
}

void ex3()
{
	std::vector<int> v{1, 2, 3, 4};
	std::vector<int>::const_iterator it;
	// this marks the structure as being unmutable therefore it is better
	for (it = v.cbegin(); it != v.cend(); ++it)
	{
		// *it *= 2; trows an error
		std::cout << *it << std::endl;
	}
}

// this does not work given that cbegin returns a const_iterator while begin can return both
////void ex4()
//{
//	std::vector<int> v{1, 2, 3, 4};
//	std::vector<int>::iterator it;
//	// this marks the structure as being unmutable therefore it is better
//	for (it = v.cbegin(); it != v.cend(); ++it)
//	{
//		// *it *= 2; trows an error
//		std::cout << *it << std::endl;
//	}
//}

int main()
{
	ex1();
	ex2();
	ex3();
	return 0;
}
