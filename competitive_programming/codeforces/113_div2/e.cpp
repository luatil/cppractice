#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

using ll = long long;
using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

const ll inf = numeric_limits<ll>::max() / 4;
const ll MOD = (1e9) + 7;

const int D = 0;
const int A = 1;
const int B = 2;
const int C = 3;

int old_memo[4];
int memo[4];

int mod_sum(int a, int b, int c) {
    return ((a+b)%MOD+c)%MOD;
}

int main() {
    int n; cin >> n;

    old_memo[D] = 1;
    old_memo[A] = 0;
    old_memo[B] = 0;
    old_memo[C] = 0;

    for(int i=1; i<=n; i++) {
        memo[D] = mod_sum(old_memo[A], old_memo[B], old_memo[C]);
        memo[A] = mod_sum(old_memo[D], old_memo[B], old_memo[C]);
        memo[B] = mod_sum(old_memo[A], old_memo[D], old_memo[C]);
        memo[C] = mod_sum(old_memo[A], old_memo[B], old_memo[D]);
        old_memo[D] = memo[D];
        old_memo[A] = memo[A];
        old_memo[B] = memo[B];
        old_memo[C] = memo[C];
    }

    cout << memo[D] << '\n';
}