#include <iostream>

void simulate(long long n) 
{
    while(n>1)
    {
        std::cout << n << ' ';
        if((n&1)==0) n /= 2;
        else 
        {
            n *= 3;
            n++;
        } 
    }
    std::cout << n << '\n';
}

int main()
{
    long long n; std::cin >> n;
    simulate(n);
}