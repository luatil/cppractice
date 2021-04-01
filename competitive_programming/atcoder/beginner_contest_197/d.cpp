#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long
const double PI = 3.14159265358979323846;

void solve()
{
    int n; cin >> n;
    double x0, y0; cin >> x0 >> y0;
    double x2, y2; cin >> x2 >> y2;

    const double px = (x2 - x0) /2.0 + x0;
    const double py = (y2 - y0) /2.0 + y0; 

    const double cosi = cos(2*PI/n);
    const double sini = sin(2*PI/n);

    const double x_pos = (x0 - px) * cosi - sini * (y0 - py);
    const double y_pos = (x0 - px) * sini + cosi * (y0 - py);

    cout << x_pos + px << ' ' << y_pos + py << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}