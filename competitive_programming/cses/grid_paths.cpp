#include <bits/stdc++.h>
using namespace std;

#define ll long long


string s;
bool vis[7][7];
ll ans = 0;

void dfs(int i, int j, int pos) {

    if(vis[i][j]) {
        return;
    }

    if(i == 0 && j == 6) {
        if(pos == 48) {
            ans++;
        }
        return;
    }


    // R OPT
    if(i == 6 || vis[i+1][j]) {
        if(j > 0 && j < 6 && !vis[i][j-1] && !vis[i][j+1] && i > 0 && vis[i-1][j]) {
            return;
        }
    }

    // L OPT
    if(i == 0 || vis[i-1][j]) {
        if(j > 0 && j < 6 && !vis[i][j-1] && !vis[i][j+1] && i < 6 && vis[i+1][j]) {
            return;
        }
    }

    // D OPT
    if(j == 6 || vis[i][j+1]) {
        if(i > 0 && i < 6 && !vis[i-1][j] && !vis[i+1][j] && j > 0 && vis[i][j-1]) {
            return;
        }
    }

    // U OPT
    if(j == 0 || vis[i][j-1]) {
        if(i > 0 && i < 6 && !vis[i-1][j] && !vis[i+1][j] && j < 6 && vis[i][j+1]) {
            return;
        }
    }

    vis[i][j] = true;


    // R
    if((s[pos] == 'R' || s[pos] == '?') && i < 6 && !vis[i+1][j]) {
        dfs(i+1, j, pos+1);
    }

    // L
    if((s[pos] == 'L' || s[pos] == '?') && i > 0 && !vis[i-1][j]) {
        dfs(i-1, j, pos+1);
    }

    // D
    if((s[pos] == 'D' || s[pos] == '?') && j < 6 && !vis[i][j+1]) {
        dfs(i, j+1, pos+1);
    }

    // U
    if((s[pos] == 'U' || s[pos] == '?') && j > 0 && !vis[i][j-1]) {
        dfs(i, j-1, pos+1);
    }
    
    vis[i][j] = false;
}


int main() 
{
    cin >> s;
    memset(vis, 0, sizeof(vis));
    dfs(0, 0, 0);
    cout << ans << '\n';
}
