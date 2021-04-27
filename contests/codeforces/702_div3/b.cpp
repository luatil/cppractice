#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long

const int SIZE = 1e5 + 7;

void solve()
{
    int n; cin >> n; // n%3 == 0 && 0 < n < 100
    vector<int> v(n);
    REP(i, n) cin >> v[i];

    int n0 = count_if(all(v), [](auto e) { return (e%3==0); });
    int n1 = count_if(all(v), [](auto e) { return (e%3==1); });
    int n2 = count_if(all(v), [](auto e) { return (e%3==2); });

    int total = 0;

    while(max(n0, max(n1, n2)) > n/3 )
    {
        int zero_to_one = max(0, n0-(n/3));
        int one_to_two  = max(0, n1-(n/3));
        int two_to_zero = max(0, n2-(n/3));

        total += zero_to_one + one_to_two + two_to_zero;

        n0 += two_to_zero;
        n0 -= zero_to_one;
        n1 += zero_to_one;
        n1 -= one_to_two;
        n2 += one_to_two;
        n2 -= two_to_zero;
    }

    cout << total << '\n';
}


int main()
{
    int t; cin >> t;
    while(t--)
        solve();
}
