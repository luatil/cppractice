#include <bits/stdc++.h>
using namespace std;

#define NUM 100'000'000
//#define NUM 100

// std::vector<bool>primes(NUM, 1); much slower but more compact
std::vector<char>primes(NUM, 1);

template <typename T>
void print(T v)
{
	for (const auto & el : v) cout << el << " ";
	cout << "\n";
}

auto generate_sieve(int N) -> std::vector<int> 
{
	std::vector<int> v{2};
	v.reserve(sqrt(NUM));
	for(int i = 3; i < N; i+=2)
	{
		if(primes[i]) 
		{
			for(int j = 2; j * i < N; ++j) primes[i * j] = 0;
			v.push_back(i);
		}
	}

	return v;
}

int main()
{
	const std::vector<int> v = generate_sieve(NUM);
	print(v);
}
