#include <iostream>
#include <algorithm>
#include <string>

void reverse_string(string& s)
{
	std::reverse(std::begin(s), std::end(s));
}

void call_reverse()
{
	string s{"asdf"};
	cout << s << endl;
	reverse_string(s);
	cout << s << endl;
}

int main()
{
	call_reverse();
}
