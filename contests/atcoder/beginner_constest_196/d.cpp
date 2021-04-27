#include <iostream>
using namespace std;

int H, W, A, B, ans = 0;
void dfs(int i, int bit, int A, int B)
{
    if(i == H*W) return (void)ans++;
}

int main()
{
    cin >> H >> W >> A >> B;
    dfs(0, 0, A, B);
    cout << ans << endl;
}
