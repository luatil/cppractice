#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long
#define vi vector<int>

vi posx = {0, 1, 0, -1};
vi posy = {1, 0, -1, 0};

void solve()
{
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    vector<vector<char>> v(h, vector<char>(w));
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            cin >> v[i][j];
        }
    }
    x--;
    y--;

    // up

    int ans = 0;
    for(int i = 1; x - i >= 0; i++)
    {
        if(v[x-i][y] == '#') break;
        else ans++;
    }

    for(int i = 1; x + i < h; i++)
    {
        if(v[x+i][y] == '#') break;
        else ans++;
    }

    for(int i = 1; y - i >= 0; i++)
    {
        if(v[x][y-i] == '#') break;
        else ans++;
    }

    for(int i = 1; y + i < w; i++)
    {
        if(v[x][y+i] == '#') break;
        else ans++;
    }



    cout << ans +1 << '\n';

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
