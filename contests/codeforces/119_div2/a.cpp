#include <bits/stdc++.h>
using namespace std;

int memo[4005];
int n, a, b, c;

int dp(int i) {

    if(i < 0) return -10000000;
    if(memo[i] != -1) {
        return memo[i];
    }

    memo[i] = 1 + max({dp(i-a), dp(i-b), dp(i-c)});

    return memo[i];
}

int main() {
    cin >> n >> a >> b >> c;
    memset(memo, -1, sizeof(memo));
    memo[0] = 0;
    cout << dp(n) << '\n';
    
}
