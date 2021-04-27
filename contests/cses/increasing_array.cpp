#include <iostream>
#include <vector>

auto minimun_amount_of_increases(std::vector<int> v) -> long long
{
    long long total = 0;
    long long curr  = 0;
    for(uint i = 1; i < v.size(); i++)
    {
        curr = v[i-1] - v[i];
        total += (curr)*(curr>0);
        v[i] = (curr > 0 ? v[i-1]  : v[i]);
    }
    return total;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for(auto &el : v) std::cin >> el;

    const long long ans = minimun_amount_of_increases(v);
    std::cout << ans << '\n';
}
