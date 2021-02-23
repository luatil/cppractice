#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long

const int SIZE = 1e5 + 7;

int query(int l, int r)
{
    cout << "? " << l << " " << r << endl;
    int ans; cin >> ans;
    return ans;
}

void solve()
{
    int n; cin >> n;

    int l = 1; int r = n;

    while(r - l > 1)
    {
        int mid = (r+l)/2;

        int smax = query(l, r);

        if(smax < mid)
        {
            if(query(l, mid) == smax) r = mid;
            else l = mid;
        }

        else 
        {
            if(query(mid, r) == smax) l = mid;
            else l = mid;
        }


    }

    cout << "! " << r << '\n';
}

int main()
{
    solve();
}
