#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long
#define vi vector<int>

const int SIZE = 1e5 + 7;

void tree_maker(const vi& v, vi& tree, int l, int r, int d)
{
    if(r < l) {
        return;
    }
    if(l == r) {
        tree[l] = d;
        return;
    }
    int m = l;
    for(int i = l + 1; i <= r; i++) {
        if(v[m] < v[i]) {
            m = i;
        }
    }

    tree[m] = d;
    tree_maker(v, tree, l, m-1, d+1);
    tree_maker(v, tree, m+1, r, d+1);
}

void solve()
{
    int n; cin >> n;
    vi v(n);
    for(auto& el : v) cin >> el;
    vi result(n);
    tree_maker(v, result, 0, v.size()-1, 0);

    for(const auto&el : v) cout << el << ' ';
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--)
        solve();
}
