#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long

// const int N = 2*(1e5) + 55;
const int N = 10;
int L[N];
int R[N];
int memo[N][2];

#define Left 0
#define Right 1

ll dp(int i, int j) {

    if(memo[i][j] != -1) return memo[i][j];

    // And this is also wrong. 
    if(i == 1) {
        if(j == Left) {
            memo[i][j] = abs(R[i] - L[i]);
        }
        if(j == Right) {
            memo[i][j] = abs(R[i] - L[i]);
        }
        return memo[i][j];
    }

    if(j == Left) {
        memo[i][j] = R[i] - L[i] + min(dp(i-1, Left) + abs(L[i-1] - R[i]), dp(i-1, Right) + abs(R[i-1] - R[i]));
    }
    if(j == Right) {
        memo[i][j] = R[i] - L[i] + min(dp(i-1, Left) + abs(L[i-1] - L[i]), dp(i-1, Right) + abs(R[i-1] - L[i]));
    }

    return memo[i][j];
}

// Also have to set some variable first_id. 
void solve()
{
    int n; cin >> n;
    memset(L, 1, sizeof(L));
    memset(R, -1, sizeof(R));  
    memset(memo, -1, sizeof(memo));
    int pos; int id; int last_id = 0;
    for(int i = 0; i < n; i++) {
        cin >> pos >> id;
        L[id] = min(L[id], pos);
        R[id] = max(R[id], pos);
        last_id = max(last_id, id);
    }

    cout << min(R[last_id] + dp(last_id, Right), L[last_id] + dp(last_id, Left)) << '\n';

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}