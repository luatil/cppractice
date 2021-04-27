#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;

	string s;
	char k;

	for(int i = 0; i < N; i++) {
		cin >> s;
		k = s[s.size() - 1];
		if(k == 'u') cout << "JAPANESE" << endl;
		else if(k == 'o') cout << "FILIPINO" << endl;
		else if(k == 'a') cout << "KOREAN" << endl;
	}

	return 0;
}
