#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<string> rec(int n) 
{
    if(n == 0) {
        return {"0"};
    }

    if(n == 1) {
        return {"0", "1"};
    }

    vector<string> ans0 = rec(n-1);
    for(auto&el : ans0) {
        el.insert(el.begin(), '0');
    }
    vector<string> ans1 = rec(n-1);
    reverse(ans1.begin(), ans1.end());
    for(auto&el : ans1) {
        el.insert(el.begin(), '1');
    }

    copy(ans1.begin(), ans1.end(), back_inserter(ans0));

    return ans0;

}

int test() 
{
    int n; cin >> n;
    vector<string> ans = rec(n);
    for(auto&el : ans) cout << el << '\n';
}

void bit() 
{
    int n; cin >> n;

    for (int i = 0; i < (1 << n); i++)
    {
        int val = (i ^ (i >> 1));
         
        bitset<16> r(val);
         
        string s = r.to_string();
        cout << s.substr(16 - n) << "\n";
    }

}

int main() 
{
    test();
}