#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long

const int inf = (int) 1e9 + 7;

bool is_valid(string s)
{
    stack<char> stk;
    for(auto& el : s)
    {
        if(el == '(') stk.push('(');
        else if(el == ')')
        {
            if(stk.empty()) 
            {
                return false;
            }
            else stk.pop();
        }
    }
    return (stk.empty() ? true : false);
}

void solve()
{
    string s; 
    cin >> s;
    string temp(s.begin(), s.end());
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'A') temp[i] = '(';
        else if (s[i] == 'B') temp[i] = '(';
        else if (s[i] == 'C') temp[i] = ')';
    }

    if(is_valid(temp)) 
    {
        cout << "YES";
        return;
    }

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'A') temp[i] = '(';
        else if (s[i] == 'B') temp[i] = ')';
        else if (s[i] == 'C') temp[i] = '(';
    }

    if(is_valid(temp)) 
    {
        cout << "YES";
        return;
    }

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'A') temp[i] = ')';
        else if (s[i] == 'B') temp[i] = '(';
        else if (s[i] == 'C') temp[i] = '(';
    }

    if(is_valid(temp)) 
    {
        cout << "YES";
        return;
    }

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'A') temp[i] = '(';
        else if (s[i] == 'B') temp[i] = ')';
        else if (s[i] == 'C') temp[i] = ')';
    }

    if(is_valid(temp)) 
    {
        cout << "YES";
        return;
    }

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'A') temp[i] = ')';
        else if (s[i] == 'B') temp[i] = '(';
        else if (s[i] == 'C') temp[i] = ')';
    }

    if(is_valid(temp)) 
    {
        cout << "YES";
        return;
    }

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'A') temp[i] = ')';
        else if (s[i] == 'B') temp[i] = ')';
        else if (s[i] == 'C') temp[i] = '(';
    }

    if(is_valid(temp)) 
    {
        cout << "YES";
        return;
    }

    cout << "NO";
}

int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        solve();
        cout << '\n';
    }
}
