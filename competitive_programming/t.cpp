#include <bits/stdc++.h>
using namespace std;


int add(int a, int b, int M)
{
    const int sum = a + b;
    return (sum >= M ? sum - M : sum);
}

void sol1()
{
    const int sol = add(3, 5, 7);
    cout << sol << '\n';
}

void sol2()
{
    const int sol = add(3, 5, 3);
    cout << sol << '\n';
}

int main()
{
    sol1();
    sol2();
}
