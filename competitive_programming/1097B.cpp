#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long

const long long inf = (long long) 1e18+6;

void brute_force_solve()
{
    int n; cin >> n;
    vector<int> rotations(n);
    for(auto& el : rotations) cin >> el;
    unsigned long long mask = 0;
    bool solvable = false;

    while(mask != 0b1111111111111111)
    {
        
    }

    cout << (solvable ? "YES" : "NO") << '\n';
}

void solve()
{
    int n; cin >> n;
    vector<int> rotations(n);
    for(auto& el : rotations) cin >> el;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    brute_force_solve();
}
