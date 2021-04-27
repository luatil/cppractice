#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <iostream>

auto get_reversed_order_subtracting_two(const int n) -> std::vector<int>
{
    std::vector<int> reversed;
    reversed.reserve(n/2+1); // That's a mouthfull
    for(int i = n; i > 0; i-= 2)
        reversed.push_back(i);
    return reversed;
}

auto beautiful_permutation(const int n) -> std::string
{
    if(n == 1) return "1\n";
    if(n < 4)  return "NO SOLUTION\n";
    auto v1 = get_reversed_order_subtracting_two(n-1);
    auto v2 = get_reversed_order_subtracting_two(n);

    std::ostringstream vts;
    std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(vts, " "));
    std::copy(v2.begin(), v2.end()-1, std::ostream_iterator<int>(vts, " "));
    // Add the element with no delimiter
    vts << v2.back();

    return vts.str();
}

int main()
{
    int n; 
    std::cin >> n;
    std::cout << beautiful_permutation(n) << std::endl;
}
