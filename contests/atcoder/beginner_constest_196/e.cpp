#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = numeric_limits<ll>::max() / 4;
void chmin(ll& a, ll b){ if(a > b) a = b; }
void chmax(ll& a, ll b){ if(a < b) a = b; }

int main(){
    ll N;
    cin >> N;
    ll low = -INF, high = INF, add = 0;
    for(ll i = 0; i < N; i++){
        ll A, T;
        cin >> A >> T;
        if(T == 1){
            low += A;
            high += A;
            add += A;
        }
        else if(T == 2){
            chmax(low, A);
            chmax(high, A);
        }
        else{
            chmin(low, A);
            chmin(high, A);
        }
    }
    ll Q;
    cin >> Q;
    for(ll i = 0; i < Q; i++){
        ll x;
        cin >> x;
        cout << clamp(x + add, low, high) << '\n';
    }
}