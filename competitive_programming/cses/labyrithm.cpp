#include <bits/stdc++.h> 
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using oset = tree<T,null_type,less_equal<T>,rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mkp make_pair

const ll inf = numeric_limits<ll>::max() / 4;
const ll MOD = ll(1e9) + 7;

const int N = 1003, M = 1003;
int n, m;
char mapi[N][M];
bool visited[N][M];
int dist[N][M];
char parent[N][M];

const int px[] = {1, 0, -1, 0};
const int py[] = {0, -1, 0, 1};
const char mask[] = "DLUR";

void bfs(int i, int j) {

    queue<pair<int, int>> q;
    dist[i][j] = 0;
    parent[i][j] = -1;
    visited[i][j] = true;
    q.push({i, j});

    while(!q.empty()) {
        auto curr = q.front(); q.pop();
        for(int k = 0; k < 4; k++) {
            int nx = curr.f + px[k];
            int ny = curr.s + py[k];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && mapi[nx][ny] != '#') {
                q.push({nx, ny});
                visited[nx][ny] = true;
                dist[nx][ny] = 1 + dist[curr.f][curr.s];
                parent[nx][ny] = mask[k];
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    pi apos, bpos;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mapi[i][j];
            if(mapi[i][j] == 'A') {
                apos = {i, j};
            }
            if(mapi[i][j] == 'B') {
                bpos = {i, j};
            }
        }
    }

    bfs(apos.f, apos.s);

    if(visited[bpos.f][bpos.s]) {
        cout << "YES\n";
        cout << dist[bpos.f][bpos.s] << '\n';
        pi pos = bpos;
        string str;
        while (pos != apos) {
            char c = parent[pos.f][pos.s];
            pos = [&]() {
                switch (c) {
                case 'U':
                    return mkp(pos.f+1, pos.s);
                case 'D':
                    return mkp(pos.f-1, pos.s);
                case 'R':
                    return mkp(pos.f, pos.s-1);
                case 'L':
                    return mkp(pos.f, pos.s+1);
                }
            }();
            str.push_back(c);
        }
        reverse(all(str));
        cout << str << '\n';
    } else {
        cout << "NO\n";
    }
}