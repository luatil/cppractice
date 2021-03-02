#include <iostream>

void print_subtracting_two(int n)
{
    for(int i = n; i > 0; i-= 2)
    {
        std::cout << i << ' ';
    }
}

void beautiful_permutation(int n)
{
    if(n==1)   std::cout << "1";
    else if(n < 4)  std::cout << "NO SOLUTION";
    else if(n==4) std::cout << "2 4 1 3";
    else 
    {
        // This evens/odds or odds/evens combinations works
        print_subtracting_two(n);
        print_subtracting_two(n-1);
    }
    std::cout << std::endl;
}

int main()
{
    int n; 
    std::cin >> n;
    beautiful_permutation(n);
}
