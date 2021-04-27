#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<vector<char>> board(8, vector<char>(8));
ll total = 0;

void rec(const vector<vector<char>>& bd, int layer, set<int> cols, set<int> white, set<int> dark) {
    if(layer == 8) {
        total ++;
        return;
    }
    
    for(int i = 0; i < 8; i++) {
        if(bd[layer][i] != '*' && cols.count(i) == 0 && white.count(layer + i) == 0 && dark.count(layer - i + 7) == 0) {
            cols.insert(i);
            white.insert(layer + i);
            dark.insert(layer - i + 7);
            rec(bd, layer+1, cols, white, dark);
            cols.erase(i);
            white.erase(layer + i);
            dark.erase(layer - i + 7);
        }
    }
}

int main() 
{
    for(auto&row : board) {
        for(auto&el : row) {
            cin >> el;
        }
    }

    rec(board, 0, {}, {}, {});

    cout << total << '\n';
}