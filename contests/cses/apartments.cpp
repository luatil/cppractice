#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() 
{
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n);
    for(auto&el : a) cin >> el;
    
    vector<int> b(m);
    for(auto&el : b) cin >> el;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int up = 0, down = 0;
    int ans = 0;
    while(up < a.size() && down < b.size()) {
        if(abs(a[up] - b[down]) <= k) {
            ans++;
            up++;
            down++;
        }
        else if(a[up] - b[down] > k) {
            down++;
        }
        else {
            up++;
        }
    }

    cout << ans << '\n';

}
