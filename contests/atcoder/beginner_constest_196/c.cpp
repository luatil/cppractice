#include <bits/stdc++.h>
using namespace std;
using ll = long long; 

int main()
{
    ll N; 
    cin >> N;
    for(ll i = 0; ; i++) if(stoll(to_string(i) + to_string(i)) > N)
    {
        cout << i-1 << endl;
        return 0;
    }
}
