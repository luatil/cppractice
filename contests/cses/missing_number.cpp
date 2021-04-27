#include <iostream>
#include <vector>
#include <numeric>

// Simple problem that requires you to know the formula for PA sum -> (n*n+1)/2

auto find_missing_number(const std::vector<int>& v) -> int
{
    const long long vector_sum = std::accumulate(v.cbegin(), v.cend(), 0LL);
    const long long pa_sum     = ((v.size()+1) * (v.size()+2)) / 2;
    return pa_sum - vector_sum; 
}

int main()
{
    int n; 
    std::cin >> n;
    std::vector<int> numbers(n-1);

    for(auto& el : numbers) std::cin >> el;

    const int missing = find_missing_number(numbers);
    std::cout << missing << '\n';
}