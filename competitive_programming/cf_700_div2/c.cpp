#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, a, n) for(int i = a; i < n; i++)

// Step 1: think about string of > and < 
//INF 3 2 1 4 5 INF
//   > > > < < < 

int main()
{
	int N; cin >> N;
	int lo = 0; 
	int hi = N;
	while(hi - lo > 1) {
		int md = (lo + hi) / 2;
		cout << '?' << ' ' << md << '\n' << flush;

	}

}
