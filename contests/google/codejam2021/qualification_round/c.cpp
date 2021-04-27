#include <bits/stdc++.h>
using namespace std;

void output_vector(vector<int>& v)
{
    for(const auto&el : v) cout << el << " ";
}

int reversort(vector<int> L) 
{
    int total = 0;
    
    for(unsigned int i = 0; i < L.size() - 1; i++) {
        auto it = min_element(L.begin() + i, L.end());
        reverse(L.begin()+i, it+1);
        total += distance(L.begin(), it) - i + 1;
    }
    return total;
}

bool possible(int n, int c) {
    return c >= n-1 && c <= n*(n+1)/2 -1;
}

int max_val(int n) {
    return n*(n+1)/2 -1;
}

vector<int> rec(int n, int c) {
    if(n == 1) return {1};
    int x = max(1, c - max_val(n-1));
    vector<int> ans = rec(n-1, c-x);
    for(auto&el : ans) el++;
    ans.insert(ans.begin(), 1);
    reverse(ans.begin(), ans.begin() + x);
    return ans;
}

void solve(int index)
{
    int n, c; cin >> n >> c;
    cout << "Case #" << index << ": ";
    if(possible(n, c))
    {
        vector<int> v = rec(n, c);
        output_vector(v);
    }
    else
    {
        cout << "IMPOSSIBLE";
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    int index = 1;
    while(t--) {
        solve(index);
        index++;
    }
}