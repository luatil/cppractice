#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() 
{
    int n; cin >> n;
    set<int> st;
    int temp;
    for(int i = 0; i < n; ++i) {
        cin >> temp;
        st.insert(temp);
    }
    cout << st.size() << '\n';
}