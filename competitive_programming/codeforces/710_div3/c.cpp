#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long
#define vi vector<int>

template<typename T> 
void output_vector(T v)
{
    for(const auto& el : v) cout << el << ' ';
    cout << '\n';
}


const int inf = 200;
const int N = 23;
int memo[N][N][N][N];
int equal[N][N][N][N];


int dp(const string& s, const string& t, int sl, int sr, int tl, int tr)
{
    if(memo[sl][sr][tl][tr] == -1)
    {
        memo[sl][sr][tl][tr] = [&](){

            if((tr - tl) == (sr - sl))
            {
                int index = 0;
                while(s[sl+index] == t[tl+index]) index++;
                if(index == (1+sr - sl)) return 0;
            }
// 
            if(sl == sr) {
                if(tr == tl) {
                    if(s[sl] == t[tl]) return 0;
                    return 2;
                }
                return 1 + min(dp(s, t, sl, sr, tl, tr-1), dp(s, t, sl, sr, tl+1, tr));
            }
            if(tl == tr) {
                if(sl == sr) {
                    if(s[sl] == t[tl]) {
                        return 0;
                    }
                    return 2;
                }
                return 1 + min(dp(s, t, sl, sr-1, tl, tr), dp(s, t, sl+1, sr, tl, tr));
            }
            if(sl > sr) return inf;
            if(tl > tr) return inf;
            return 1 + min({
                        dp(s, t, sl+1, sr, tl, tr),
                        dp(s, t, sl, sr-1, tl, tr),
                        dp(s, t, sl, sr, tl+1, tr),
                        dp(s, t, sl, sr, tl, tr-1)});
        }();
    }
    return memo[sl][sr][tl][tr];
}

void solve()
{
    string a, b;
    cin >> a >> b;
    for(int i = 0; i < a.size(); i++)
    {
        for(int j = 0; j < a.size(); j++)
        {
            for(int k = 0; k < b.size(); k++)
            {
                for(int g = 0; g < b.size(); g++)
                {
                    memo[i][j][k][g] = -1;
                }
            }
        }
    }
    cout << dp(a, b, 0, a.size()-1, 0, b.size()-1) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--)
        solve();
}
