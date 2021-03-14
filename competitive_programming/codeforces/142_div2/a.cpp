#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for (int i = a; i < b; i++)

vector< pair<int, int>> v;
pair< int, int > p;

int main() {
    int s, n;
    cin >> s >> n;
    int dstr, dbon;
    REP(i, 0, n) {
        cin >> dstr >> dbon;
        p.first = dstr;
        p.second = dbon;
        v.push_back(p);
    }

    sort(v.begin(), v.end());

    REP(i, 0, n) {
        if(s <= v[i].first) {
            cout << "NO" << endl;
            return 0;
        } else {
            s+=v[i].second;
        }
    }

    cout << "YES" << endl;

//    REP(i, 0, n) {
//        cout << "dstr: " << v[i].first << " dbon: " << v[i].second << endl;
//    }
    return 0;
}