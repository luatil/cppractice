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

    unsigned long long total = 0;

    for(unsigned long long mask = 0; mask < 1 << n; mask++)
    {
        total = 0;
        for(int i = 0; i < n; i++)
        {
            if(mask >> i & 1) total += rotations[i];
            else total -= rotations[i];
        }
        if(total == 0 || total % 360 == 0)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

auto find_if_combinations_are_valid(const vector<int>& rotations) -> bool
{
     
}

void dp_solve()
{
    int n; cin >> n;
    vector<int> rotations(n);
    for(auto& el : rotations) cin >> el;

    cout << (find_if_combinations_are_valid(rotations) ? "YES" : "NO") << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    dp_solve();
}
