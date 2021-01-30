#include <iostream>
#include <set>
#include <map>
using namespace std;

void set_example()
{
	set<int> s{1, 20, 0, 33};
	auto length = s.size();

	auto x = 100;
	auto val = 200;

	s.insert(x);
	s.erase(val);

	set<int>::iterator itr1 = s.find(val);
	set<int>::iterator itr2 = s.find(100);

	cout << *itr1 << endl;
	cout << *itr2 << endl;
}

void map_example()
{
	map<string, int>m{{"hello", 9}, {"this", 13}};
	int length = m.size();
	m.insert(make_pair("hello", 9));
	m.erase("this");

	map<string, int>::iterator itr=m.find("hello");

	cout << itr->first << " " << itr->second << endl;

	cout << m["hello"] << endl;

	// OR 
	
	auto & [a, b] = m.find("hello");

	cout << *a << " " << *b << endl;




}


int main()
{

	map_example();
	return 0;
}
