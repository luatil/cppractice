#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long

void jump(vector<ll>& v, int index)
{
    while(index < v.size())
    {
        int new_index = index + v[index];
        v[index] -= (v[index] == 1 ? 0 : 1);
        index = new_index;
    }
}

void solve()
{
    int num_of_trampolines; cin >> num_of_trampolines;
    vector<ll> trampolines(num_of_trampolines);
    vector<ll> jumps(num_of_trampolines);
    for(auto &el : trampolines) cin >> el;

    ll total_jumps = 0;
    for(int i = 0; i < num_of_trampolines; i++)
    {
        if(trampolines[i] == 1) continue;
        const int remaining_trampolines = (num_of_trampolines - i) - 1;
        if(trampolines[i] > remaining_trampolines)
        {
            const int over_jumps = trampolines[i] - remaining_trampolines -1*(remaining_trampolines==0);
            total_jumps += over_jumps;
            trampolines[i] = remaining_trampolines;
        }
        for(int j = 0; j < trampolines[i]-1; j++)
        {
            total_jumps +=1;
            jump(trampolines, i);
        }
    }

    cout << total_jumps << '\n';
}

int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
        solve();
}
