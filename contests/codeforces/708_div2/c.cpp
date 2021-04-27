#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long

template<typename T> 
void output_vector(T v)
{
    for(const auto& el : v) cout << el << ' ';
    cout << '\n';
}

vector<int> find_3_min(int a)
{
    const vector<int> ans = [&]()
    {
        if(__builtin_popcount(a) == 1 || a %4 == 0) return (vector<int>){a/2, a/4, a/4};
        else if(a%2 == 1) return (vector<int>){1, (a-1)/2, (a-1)/2};
        return (vector<int>){2, (a-2)/2, (a-2)/2};
    }();
    return ans;
}

vector<int> find_min(int a, int b)
{
    vector<int> ans;
    while(b > 3)
    {
        ans.push_back(1);
        a--;
        b--;
    }
    vector<int> easy = find_3_min(a);
    copy(easy.begin(), easy.end(), back_inserter(ans));
    return ans;
}

void solve()
{
    int n, k; cin >> n >> k;
    vector<int> ans = find_min(n, k);
    output_vector(ans);
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
