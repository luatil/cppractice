#include <bits/stdc++.h>
using namespace std;

#define ll long long

int table[30];

int main() 
{
    string s; cin >> s;
    for(auto& el : s) ++table[el - 'A'];

    int total = 0;
    int single = -1;

    for(int j = 0; j < 30; j++) {
        if(table[j] % 2 == 1) {
            total ++;
            single = j;
        }
    }

    if(total > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    for(int j = 0; j < 30; j++) {
        for(int i = 0; i < table[j]/ 2; i++) {
            printf("%c", j+'A');
        }
    }

    if(single != -1) {
        printf("%c", single + 'A');
    }

    for(int j = 28; j >= 0; j--) {
        for(int i = 0; i < table[j]/2; i++) {
            printf("%c", j+'A');
        }
    }
}