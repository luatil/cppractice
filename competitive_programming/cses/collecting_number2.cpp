#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
const ll inf = numeric_limits<ll>::max() / 4;

int main() 
{
    int n, m; cin >> n >> m;
    vector<pi> v(n+1);
    vi t(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> v[i].f;
        v[i].s = i;
        t[i] = v[i].f;
    }
    sort(all(v));
    ll ans = 1;
    for(int i = 2; i <= n; i++) {
        if(v[i].s < v[i-1].s) {
            ans++;
        }
    }

    int a, b, va, vb, tot = 0;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;

        va = t[a]; vb = t[b];

        if(va > 1 && v[va].s < v[va-1].s) {
            tot--;
        }
        if(va + 1 <= n && v[va+1].s < v[va].s) {
            tot--;
        }
        if(vb > 1 && v[vb].s < v[vb-1].s && vb-1 != va) {
            tot--;
        }
        if(vb + 1 <= n && v[vb+1].s < v[vb].s && vb +1 != va) {
            tot--;
        }



        v[va].s = b; v[vb].s = a;
        swap(t[a], t[b]);

        if(va > 1 && v[va].s < v[va-1].s) {
            tot++;
        }
        if(va + 1 <= n && v[va+1].s < v[va].s) {
            tot++;
        }
        if(vb > 1 && v[vb].s < v[vb-1].s && vb-1 != va) {
            tot++;
        }
        if(vb + 1 <= n && v[vb+1].s < v[vb].s && vb +1 != va) {
            tot++;
        }

        ans += tot;
        tot = 0;
        cout << ans << '\n';
    }
}