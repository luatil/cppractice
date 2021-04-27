#include <bits/stdc++.h>
using namespace std;

char panel[5][5];
int arr[18];

int main() {
    int h;
    cin >> h;

    char aux;
    int pos;

    for (int i = 0; i < 16; i++)
    {
        cin >> aux;
        if(aux == '.');
        else {
          pos = (int)aux - 48;
          arr[pos]++;
        }
    }
    
    /*for (int i = 0; i < 16; i++)
    {
        cout << arr[i] << " ";
    }*/
    
    for(int i = 0; i < 16; i++) {
        if(h*2 < arr[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
    
}