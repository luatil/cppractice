#include <bits/stdc++.h>
using namespace std;

template<typename T> 
void output_vector(T v)
{
    for(const auto& el : v) cout << el << ' ';
    cout << '\n';
}

// Primes up to N
const int N = 100;
int sieve_helper[N+1];
vector<int> primes;

void fill_sieve_linear_time()
{
    for (int i=2; i<=N; ++i) {
        if (sieve_helper[i] == 0) {
            sieve_helper[i] = i;
            primes.push_back (i);
        }
        for (int j=0; j<(int)primes.size() && primes[j]<=sieve_helper[i] && i*primes[j]<=N; ++j)
            sieve_helper[i * primes[j]] = primes[j];
    }
}

void test_sieve()
{
    fill_sieve_linear_time();
    for(const auto&el : primes) cout << el << ' ';
    cout << '\n';
}