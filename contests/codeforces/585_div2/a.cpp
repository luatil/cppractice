#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for (int i = a; i < b; i++)

int get_min(int a1, int a2, int k1, int k2, int n) {
    int tot = a1 * (k1-1) + a2 * (k2-1);
    int result;
    if(n>tot) {
        return n-tot;
    }
    return 0;
}

int get_max(int a1, int a2, int k1, int k2, int n) {
    int menor = min(k1, k2);
    int maior = max(k1, k2);
    int qtmin, qtmax;
    if(k1 == menor) {
        qtmin = a1;
        qtmax = a2;
    } else {
        qtmin = a2;
        qtmax = a1;
    }

    int tot=0;

    while(n > 0 && qtmin > 0) {
        n -= menor;
        qtmin--;
        if (n >= 0) tot++;
    }

    while(n > 0  && qtmax > 0) {
        n-= maior;
        qtmax--;
        if (n >= 0) tot++;
    }

    return tot;
}


int main() {
    int a1, a2;
    int k1, k2;
    int n;

    cin >> a1 >> a2 >> k1 >> k2 >> n;

    pair<int, int> a, b;
    a.first = a1;
    a.second = k1;
    b.first = a2;
    b.second = k2;

    cout << get_min(a1, a2, k1, k2, n);

    cout << " ";

    cout << get_max(a1, a2, k1, k2, n);

    cout << endl;

    return 0;
}