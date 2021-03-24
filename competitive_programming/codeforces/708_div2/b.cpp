#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long

void solve()
{
    ll n, m; cin >> n >> m;
    vector<ll> v(n);
    for(auto& el : v) cin >> el;
    vector<ll> table(m);

    for(auto&el : v) el = el%m;
    for(const auto&el : v) table[el]++;

    ll total = (table[0] == 0 ? 0 : 1); // the 0's

    if(m%2==0 && table[m/2] != 0) total++;

    for(ll i = 1; 2 * i < m; i++)
    {
        ll left = table[i];
        ll right = table[m-i];

        if(left == 0) total += right;
        else if(right == 0) total += left;
        else if(max(left, right) >= min(left, right) && max(left, right) <= (min(left, right) + 1))
        {
            total++;
        }
        else 
        {
            total++;
            total += max(left, right) - (min(left, right) + 1);
        }
    }

    cout << total << '\n';
}

void test()
{

}

void drive()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--)
        solve();
}

int main()
{
    drive();
}
