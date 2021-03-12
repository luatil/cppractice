#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(size_t i = 0; i < n; i++)
#define ll long long

const int SIZE = 1e5 + 7;
constexpr int plus_inf = numeric_limits<int>::max();

int just_divide(ll a, ll b)
{
    if(b == 1) return SIZE;
    if(a < b) return 1;
    if(a == b) return 2;

    return 1 + just_divide(a/b, b); // worst case is log n
}

void solve()
{
    ll a, b; cin >> a >> b;
    
    ll ans = 0;
    
    if(b == 1)
    {
        b++;
        ans++;
    }


    const int max_number_of_operations = log2(a);
    int min_number_of_operations = plus_inf;
    
    for(int i = 0; i < max_number_of_operations; ++i) 
    {
        min_number_of_operations = min(min_number_of_operations, i + just_divide(a, b+i));
    }

    cout << ans << '\n';
}   



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while(T--)
        solve();
}
