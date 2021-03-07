#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long

const int inf = (int) 1e9 + 7;

void solve()
{
    int n, q; cin >> n >> q;
    vector<int> v(n);
    for(auto & el : v) cin >> el;

    int number_of_ones = count(all(v), 1);

    int t, x, k;
    for(int i = 0; i < q; i++)
    {
        cin >> t;
        if(t==1)
        {
            cin >> x;
            v[x-1] = 1 - v[x-1];
            if(v[x-1] == 1) number_of_ones++;
            else number_of_ones--;
        }

        if(t==2)
        {
            cin >> k;
            if(k <= number_of_ones) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }
}

int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
