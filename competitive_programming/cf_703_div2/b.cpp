#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long

// WIL: 
// a 2d problem can actualy just be two 1d ones. 
// you can find the shortest distance from one point to several others in 1 dimension by finding it's median
// to find the number of elements between the numbers around the median you can sort an array and 
// use v[n/2] - v[(n-1)/2] + 1 to calculate it 
// when dealing with numbers that come around 1e9, use ll

void solve()
{
    int n; cin >> n;
    vector<long long> h(n), v(n);

    for(int i = 0; i < n; i++)
        cin >> h[i] >> v[i];

    if(n%1==1) 
    {
        cout << "NO\n";
        return;
    }

    sort(all(h));
    sort(all(v));

    cout << (h[n/2] - h[(n-1)/2] + 1) * 
            (v[n/2] - v[(n-1)/2] + 1) << '\n';

}


int main()
{
    int t; cin >> t;
    while(t--)
        solve();
}
