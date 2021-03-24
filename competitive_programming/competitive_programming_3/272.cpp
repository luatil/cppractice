#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1'000'000'000


int main()
{
    char c; 
    int index = 0;
    while(scanf("%c", &c) != EOF)
    {
        if(c == '\"') 
        {
            if(index == 0)
            {
                cout << "``";
            }
            if(index == 1)
            {
                cout << "''";
            }
            index ^= 1;
        }
        else 
        {
            if(c == ' ') cout << ' ';
            if(c == '\n') cout << '\n';
            else cout << c;
        }
    }
}

