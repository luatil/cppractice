#include <bits/stdc++.h> 
using namespace std;
const int N = 1005;
const int M = 100005;
int h[N], s[N], memo[M];
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma") 
// Simply knapsack
int main() {
    int n, x; 
    scanf("%d%d", &n, &x);
    for(int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }

    for(int i = 0; i < n; i++) {
        for(int j = x; j >= h[i]; j--) {
            memo[j] = max(memo[j], memo[j - h[i]] + s[i]);
        }
    }

    printf("%d\n", memo[x]);
    return 0;
}