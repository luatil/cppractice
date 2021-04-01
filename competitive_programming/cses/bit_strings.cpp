#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() 
{
    int n; cin >> n;
    ll total = 2;
    while(--n) {
        total = (total * 2) % (ll)(1e9+7);
    }
    cout << total;
}