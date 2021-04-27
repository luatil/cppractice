#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()

int main() 
{
    int n, x; cin >> n >> x;
    vector<pair<int, int> > v(n);
    int temp;
    for(int i =0; i< n; ++i) {
        cin >> temp;
        v[i] = {temp, i};
    }
    sort(all(v));
    int l = 0, r = n-1;
    while(l < r) {
        if(v[l].first + v[r].first == x)  {
            cout << v[l].second + 1 << ' ' << v[r].second + 1;
            return 0;
        }
        else if(v[l].first + v[r].first > x)  { 
            r--;
        }
        if(v[l].first + v[r].first < x)  {
            l++;
        }
    }
    cout << "IMPOSSIBLE\n";
}