#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long
#define vi vector<int>
const int inf = numeric_limits<int>::max() / 4;

void solve()
{
    int n, k; cin >> n >> k;
    vi a(n), b(n);
    for(auto& el : a) cin >> el;
    for(auto& el : b) cin >> el;
    vi prefix(all(a));
    transform(all(prefix), b.begin(), prefix.begin(), [](auto a, auto b){ return a * b;});
    vi suffix(all(prefix));
    partial_sum(all(prefix), prefix.begin());
    partial_sum(suffix.rbegin(), suffix.rend(), suffix.rbegin());
    vi sum;
    partial_sum(all(a), back_inserter(sum));

    int maximum = -inf;
    for(int i = 0; i + k <= n; i++)
    {
        maximum = max(maximum, (i>0)*prefix[i-1] + (sum[i+k-1] - (i>0)*sum[i-1]) + (i+k<n)*suffix[i+k]);
    }

    cout << maximum << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}