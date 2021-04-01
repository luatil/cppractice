#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() 
{
    ll n; cin >> n;
    ll sum = n*(n+1) /2;

    if(sum%2) {
        cout << "NO\n";
        return 0;
    }

    sum/=2;

    vector<int> v1, v2;

    while(n) {
        if(sum - n >= 0) {
            v1.push_back(n);
            sum -= n;
        }
        else {
            v2.push_back(n);
        }
        n--;
    }

    cout << "YES\n";
    cout << v1.size() << '\n';
    for(auto&el : v1) cout << el << ' ';
    cout << '\n';
    cout << v2.size() << '\n';
    for(auto&el : v2) cout << el << ' ';
    cout << '\n';
}