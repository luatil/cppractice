#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;

template<typename T>
void print(T v)
{
	for(const auto& el : v) std::cout << el << " ";
	std::cout << std::endl;
}

// Given an list of points on the plane, find the K closest points to the origin (0, 0)

vector<vector<int>> kClosest_1(vector<vector<int>> & points, int K)
{
	sort(begin(points), 
	     end(points),
		 [](auto const& a, auto const&b) {
			 return (a[0] * a[0] + a[1] * a[1] < 
					 b[0] * b[0] + b[1] * b[1]);
		 });

	return vector(begin(points), begin(points) + K);

}

vector<vector<int>> kClosest_2(vector<vector<int>> & points, int K)
{
	partial_sort(
		begin(points), 
		begin(points) + K, 
		end(points),
		[](auto const& a, auto const&b) {
			return (a[0] * a[0] + a[1] * a[1] < 
				    b[0] * b[0] + b[1] * b[1]);
		});

	return vector(begin(points), begin(points) + K);

}

vector<vector<int>> kClosest_3(vector<vector<int>> & points, int K)
{
	nth_element(
		begin(points), 
		begin(points) + K, 
		end(points),
		[](auto const& a, auto const&b) {
			return (a[0] * a[0] + a[1] * a[1] < 
				    b[0] * b[0] + b[1] * b[1]);
		});

	return vector(begin(points), begin(points) + K);

}

void kClosest1_ex1()
{
	vector<vector<int>> v{{1, 2}, {3, 4}, {2, 0}, {5, 3}, {9, 8}};
	for(auto el : v) { cout << "{ " << el[0] << " "<< el[1] << " }" << " " ;};
	cout << endl;
	vector<vector<int>> sol = kClosest_1(v, 2);
	for(auto el : sol) { cout << "{ " << el[0] << " " << el[1] << " }" << " " ;};
	cout << endl;
}

void kClosest2_ex1()
{
	vector<vector<int>> v{{1, 2}, {3, 4}, {2, 0}, {5, 3}, {9, 8}};
	for(auto el : v) { cout << "{ " << el[0] << " "<< el[1] << " }" << " " ;};
	cout << endl;
	vector<vector<int>> sol = kClosest_2(v, 2);
	for(auto el : sol) { cout << "{ " << el[0] << " " << el[1] << " }" << " " ;};
	cout << endl;
}

void kClosest3_ex1()
{
	vector<vector<int>> v{{1, 2}, {3, 4}, {2, 0}, {5, 3}, {9, 8}};
	for(auto el : v) { cout << "{ " << el[0] << " "<< el[1] << " }" << " " ;};
	cout << endl;
	vector<vector<int>> sol = kClosest_2(v, 2);
	for(auto el : sol) { cout << "{ " << el[0] << " " << el[1] << " }" << " " ;};
	cout << endl;
}

// The second largest element is:
void simple_example1()
{
	std::vector<int> v{4, 3, 2, 1, 0, 5};
	print(v);
	std::nth_element(v.begin(), v.begin()+1, v.end(), std::greater<int>());
	print(v);
	std::cout << "The second largest element is: " << v[1] << "\n";
}

void simple_example2()
{
	std::vector<int> v(100);
	std::iota(v.begin(), v.end(), 1);
	std::random_shuffle(v.begin(), v.end());
	print(v);

	std::nth_element(v.begin(), v.begin() + 55, v.end());
	print(v);
}

void difference_with_std_partition()
{
	std::vector<int> v(100);
	std::iota(v.begin(), v.end(), 1);
	std::random_shuffle(v.begin(), v.end());
	print(v);

	std::partition(v.begin(), v.end(), [](auto e) {return e < 55;});
	print(v);
}

// I want the 4th smallest element
void simple_example3()
{
	std::vector<int> v{3, 1, 2, 4, 5, 9, 10};
	print(v);

	std::nth_element(v.begin(), v.begin() + 3, v.end());
	print(v);
	std::cout << "The 4th smallest element is: " << v[3] << "\n";

}

/* https://codeforces.com/contest/1473/problem/A 
 * Given a vector of ints and an integer d, find if either all numbers are smaller than 
 * d or if the sum of the smallest numbers is smaller than d
*/

auto solve(int d, std::vector<int> v) -> std::string
{
	if(std::all_of(v.cbegin(), v.cend(), [&](auto e){ return e <= d; })) return "YES\n";

	std::nth_element(v.begin(), v.begin() + 2, v.end());

	return (v[0] + v[1] <= d ? "YES\n" : "NO\n");
}


int main()
{
	simple_example2();
	simple_example3();
	return 0;
}
