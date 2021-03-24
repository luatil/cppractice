#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll inf = numeric_limits<ll>::max() / 4;

ll rules[20][20];
ll meals[20];
ll memo[(1 << 19)][19];

ll find_best_course(int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        memo[1 << i][i] = meals[i];
    }

    for(int mask = 0; mask < (1 << (n+1)); mask++)
    {
        for(int i = 0; i < n; i++) 
        {
            if(mask & 1 << i)
            {
                for(int j = 0; j < n; j++)
                {
                    // this means i still haven't inserted jth element on this sequence
                    if((mask & 1 << j) == 0) 
                    {
                        memo[mask | 1 << j][j] = max(memo[mask][i] + rules[i][j] + meals[j], memo[mask | 1 << j][j]);
                    }
                }
            }
        }
    }

    ll ans = -inf;
    for(int mask = 0; mask < (1 << (n+1)); mask++)
    {
        for(int i = 0; i < n; i++)
        {
            if(__builtin_popcount(mask) == m)
            {
                ans = max(ans, memo[mask][i]);
            }
        }
    }

    return ans;
}


int main(){
    int n, m, k;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++) cin >> meals[i];

    int x, y, z;
    while(k--)
    {
        scanf("%d%d%d", &x, &y, &z); 
        rules[x-1][y-1] = z;
    }
    cout << find_best_course(n, m) << '\n';
}
