#include <iostream>
#include <string>

std::string get_reversed_order_subtracting_two(const int n)
{
    std::string reversed;
    reversed.reserve(n/2+1); // That's a mouthfull
    for(int i = n; i > 0; i-= 2)
        reversed.push_back(i);
    return reversed;
}

std::string beautiful_permutation(const int n)
{
    if(n == 1) return "1\n";
    if(n < 4)  return "NO SOLUTION\n";
    return get_reversed_order_subtracting_two(n-1);
}

int main()
{
    int n; 
    std::cin >> n;
    // std::string solution = beautiful_permutation(n);
    std::string solution = get_reversed_order_subtracting_two(n);
    std::cout << solution;
}
