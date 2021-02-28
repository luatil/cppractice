#include <vector>
#include <iostream>
#include <algorithm>

void call_any_of_example1()
{
	std::vector const v{1, 2, 3, 4, 5};

	bool const ans = std::any_of(v.cbegin(), v.cend(), [](auto const& e) { return e % 2 == 0; });

	std::cout << ans << std::endl;
}

void call_count_if_example1()
{
	std::vector const v{1, 2, 3, 4, 5};

	int const ans = std::count_if(v.cbegin(), v.cend(), [](auto const& e){ return e % 2 == 0; });

	std::cout << ans << std::endl;
}

void call_example_1()
{
	auto pet = ""s;
	if(is_cool) 
		pet = "cat"s;
	else 
		pet = "dog"s;

	auto const pet = is_cool ? "cat"s : "dog"s;

	auto const pet = [] {
		if(is_cool) {
			// some other logic/stuff
			return "cat"s;
		}
		else {
			// some other logic/stuff
			return "dog"s;
		}
	} ();
}

struct itm_Rectangle {
	int height;
	int width;
};

int call_rectangle_itm_example() {

	itm_Rectangle r;
	r.height = 2;
	r.width = 3;

	return 0;
}

struct Rectangle {
	int height;
	int width;
	Rectangle(int h, int w) :
		height{h}, width{w} {}
};

int call_non_itm_rectangle()
{
	Rectangle const r{3, 2};
}

void call_vector_itm_example()
{
	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
}

void call_vector_non_itm_example()
{
	std::vector const v = {1, 2, 3, 4, 5};
}

int main()
{
	call_example_1();
}
