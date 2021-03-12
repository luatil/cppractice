#include <vector>
#include <iostream>
using namespace std;

#define all(v) v.begin(), v.end()

void solve()
{
    int num_of_trampolines; cin >> num_of_trampolines;
    vector<int> trampolines(num_of_trampolines);
    for(auto & el : trampolines) cin >> el;

    vector<int> pekoras(num_of_trampolines);
    long long total_jumps = 0;

    for(int i = 0; i < num_of_trampolines; i++)
    {
        if(trampolines[i] > pekoras[i] + 1)
        {
            total_jumps += (trampolines[i]-1)-pekoras[i];
        }

        if(pekoras[i] + 1 > trampolines[i])
        {
            if(i < num_of_trampolines-1)
                pekoras[i+1] += 1+pekoras[i]-trampolines[i];
        }

        for(int j = min(trampolines[i]+i, num_of_trampolines-1); j > i + 1; j--)
        {
            pekoras[j]++;
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
