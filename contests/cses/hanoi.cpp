#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> ans;
ll total = 0;

void hanoi(int n, int beg, int mid, int dest) 
{
    if(n == 0) {
        return;
    }
    total++;
    hanoi(n-1, beg, dest, mid);
    ans.push_back(beg);
    ans.push_back(dest);
    hanoi(n-1, mid, beg, dest);
}

int main() 
{
    int n; cin >> n;
    hanoi(n, 1, 2, 3);
    cout << total << '\n';
    for(int i =0; i + 1 < ans.size(); i+=2) {
        cout << ans[i] << ' ' << ans[i+1] << '\n';
    }
}