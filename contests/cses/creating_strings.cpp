#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll factorial(ll n) {
    if(n == 0) {
        return 1;
    }
    return n * factorial(n-1);
}

ll number_of_strings(ll len, ll rep) {
    return factorial(len) / (factorial(rep));
}

int table[30];
int main() 
{
    string s; cin >> s;
    ll total = factorial(s.size());
    for(auto&el : s) ++table[el-'a'];
    for(auto&el : table) {
            total /= factorial(el);
    }
    cout << total << '\n';
    sort(s.begin(), s.end());
    cout << s << '\n';
    total = 0;
    while(next_permutation(s.begin(), s.end())) {
        cout << s << '\n';
    }
}