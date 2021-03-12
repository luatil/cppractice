#include <bits/stdc++.h>
using namespace std;

// Codeforces time has a ~15ms randomness
auto find_size_of_biggest_beautiful_arrangement(const vector<int>& sizes) -> long long
{
    vector<int> dp(sizes.size(), 1);
    for(unsigned int i = sizes.size()-1; i > 0; i--)
        for(unsigned int k = 2; k * i < sizes.size(); k++)
            if(sizes[i] < sizes[i*k]) 
                dp[i] = max(dp[i], dp[i*k]+1);

    return *max_element(dp.begin(), dp.end());
}

void solve()
{
    int n; cin >> n;
    vector<int> sizes(n);
    for(auto& el : sizes) cin >> el;

    sizes.push_back(0);
    rotate(sizes.begin(), sizes.end()-1, sizes.end()); // just for fun

    cout << find_size_of_biggest_beautiful_arrangement(sizes) << '\n';
}

int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; // 100
    while(t--)
        solve();
}
