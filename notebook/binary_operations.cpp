#include <iostream>
#include <string> 
#include <algorithm>
#include <vector>
using namespace std;

void print_factors_of_two(unsigned int n)
{
    for(unsigned int i = 0; 1 << i <= n; i++)
    {
        if((1 << i) & n) cout << (1<<i) << ' ';
    }
    cout << '\n';
}

void print_bits_index(unsigned int n)
{
    for(unsigned int i = 0; 1 << i <= n; i++)
    {
        if((1 << i) & n) cout << i << ' ';
    }
    cout << '\n';
}

void print_binary_representation(unsigned int n)
{
    vector<bool> binary_representation;
    for(unsigned int i = 0; 1 << i <= n; i++)
    {
        if((1 << i) & n) binary_representation.push_back(1);

        else binary_representation.push_back(0);
    }
    reverse(binary_representation.begin(), binary_representation.end());
    for(const auto& el : binary_representation) cout << el;
    cout << '\n';
}

// Returns true if theres exists a subset of v whose sum equal's the value of target
auto subset_sum(const vector<int>& v, int target) -> bool
{
    // can use int if v.size() is smaller or equal to 31
    unsigned int subset = 0;
    unsigned int max_value = (1 << v.size()+1);
    int temporary_total = 0;

    while(subset < max_value)
    {
        temporary_total = 0;
        for(int i = 0; i <= 32; i++)
        {
            if((1 << i) & subset) temporary_total += v[i];
        }
        if(temporary_total == target) return true;
        subset++;
    }
    return false;
}

auto errichto_subset_sum(const vector<int>& v, long long target) -> bool
{
    const int n = 20; // max number of elements in v
    for(int mask = 0; mask < (1 << n); mask++)
    {
        long long sum_of_this_subset = 0;
        for(int i = 0; i < n; i++)
        {
            if(mask & (1 << i)) sum_of_this_subset += v[i];
        }
        if(sum_of_this_subset == target) return true;
    }
    return false;
}

int main()
{
    unsigned int a = 13;
    vector<int> v = {2, 4, 5, 10};
    cout << (subset_sum(v, a) ? "YES" : "NO") << '\n';
}
