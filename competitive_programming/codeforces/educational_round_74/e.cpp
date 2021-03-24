#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long
#define vvi vector<vector<int>> 
#define vi vector<int> 

const int M = 21;
const int N = 10'005;
const int inf = numeric_limits<int>::max() / 4;

int n, a;
string s;
int cost[M][M];
int memo[1 << M];

void solve()
{
    // Read number of characters in string, number of letters n keyboard and the string
    cin >> n >> a >> s;

    // B represents the full set 1111..1
    const int B = ((1 << a) - 1);
    
    // Populate the cost array. cost[x][y] counts the number of adjacent x - y
    for(int i = 1; i < n; i++)
    {
        ++cost[s[i] - 'a'][s[i-1] - 'a'];
        ++cost[s[i-1] - 'a'][s[i] - 'a'];
    }

    // The string aabc has the same slowness of abc
    for(int i = 0; i < a; i++)
    {
        cost[i][i] = 0;
    }

    // Make all sets have infinite slowness before getting to them
    for(int mask = 0; mask <= B; mask++)
    {
        memo[mask] = inf;
    }

    // The empty set has 0 slowness
    memo[0] = 0;

    // Consider all sets
    for(int mask = 0; mask <= B; mask++)
    {
        // For each of them consider all the elements in the keyboard
        for(int i = 0; i < a; i++)
        {
            // If a certain letter is still not in the set
            if((mask >> i & 1) == 0)
            {
                // Create a new set with this letter
                int new_mask = mask | (1 << i);
                // Find the position this letter is gonna be put. If the set has 3 letters the new position is going to be 4
                int pos = __builtin_popcount(new_mask);
                // And them consider the option of arriving to this new_mask
                int opt = 0;
                // This next one is the really clever bit. No pun intended. 
                // For finding the cost of of moving i to j we could sum up
                // cost[i][j]*(posi - posj) for elements that already in the set, and cost[i][j]*(posj - posi)
                // for elements that are not in the set. 
                // But we do not know posj when we know posi and vice-versa.
                // But through math-magic, we can insert the part that we know, WHEN WE INSERT IT. 
                // And through algebra you can show that they are equivalent. 
                for(int j = 0 ; j < a ; j++)
                {
                    if(new_mask >> j & 1)
                    {
                        // This acts as the left part of cost[i][j]*(posx - posy)
                        opt += cost[i][j] * pos;
                    }
                    else if((new_mask >> j & 1) == 0)
                    {
                        // This acts as the right part of cost[i][j]*(posy - posx)
                        opt -= cost[i][j] * pos;
                    }
                }
                // If this option is better than what we already had for the new_mask set, make this the minimum slowness for this mask.
                memo[new_mask] = min(memo[new_mask], memo[mask] + opt);
            }
        }
    }

    // This is the minimum slowness of the full set
    cout << memo[B] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
