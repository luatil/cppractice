#include <bits/stdc++.h>
using namespace std;
 
#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long
 
template<typename T> 
void output_vector(T v)
{
    for(const auto& el : v) cout << el << ' ';
    cout << '\n';
}
 
void solve()
{
    int n; cin >> n;
    vector<long long> costs(n);
    for(auto& el : costs) cin >> el;
    vector<long long> sum_suffix = {0};
 
    partial_sum(costs.begin(), costs.end()-1, back_inserter(sum_suffix));
 
    vector<long long> min_suffix;
    int pendulum = 0;
    long long min_up = numeric_limits<int>::max();
    long long min_down = numeric_limits<int>::max();
 
    for(const auto&el : costs)
    {
        if(pendulum == 0)
        {
            if(el < min_up) 
            {
                min_up = el;
            }
            min_suffix.push_back(min_up);
        }
        if(pendulum == 1)
        {
            if(el < min_down) 
            {
                min_down = el;
            }
            min_suffix.push_back(min_down);
        }
        pendulum ^= 1;
    }
 
 
    vector<long long> min_val(n);
 
    int up = n-1; 
    int down = n;
 
    for(int i = 1; i < n; i++)
    {
        if(i%2==1)
        {
            min_val[i] = sum_suffix[i] + up*min_suffix[i-1] + down*min_suffix[i];
            down--;
        }
        if(i%2==0)
        {
            min_val[i] = sum_suffix[i] + up*min_suffix[i] + down*min_suffix[i-1];
            up--;
        }
    }
 
    //output_vector(min_suffix);
    //output_vector(min_val);
    cout << *min_element(min_val.begin()+1, min_val.end()) << '\n';
 
}
 
void drive()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--)
        solve();
}
 
int main()
{
    drive();
}