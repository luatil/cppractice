#include <bits/stdc++.h>
using namespace std;

int reversort(vector<int> & L) 
{
    int total = 0;
    
    for(unsigned int i = 0; i < L.size() - 1; i++) {
        auto it = min_element(L.begin() + i, L.end());
        reverse(L.begin()+i, it+1);
        total += distance(L.begin(), it) - i + 1;
    }
    return total;
}

void solve(int index)
{
    int n; cin >> n;
    vector<int> v(n);
    for(auto&el : v) cin >> el;
    cout << "Case #" << index << ": " << reversort(v) << '\n';
}

void test()
{
    vector<int> t1 = {4, 2, 1, 3};
    cout << reversort(t1) << '\n';
    vector<int> t2 = {1, 2};
    cout << reversort(t2) << '\n';
    vector<int> t3 = {7, 6, 5, 4, 3, 2, 1};
    cout << reversort(t3) << '\n';
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