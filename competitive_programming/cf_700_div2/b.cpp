#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = a; i < n; i++)
#define ll long long 

template <typename T> 
void print(T v)
{
	for(const auto& el: v) cout << el << " ";
	cout << "\n";
}

struct monster
{
	long long attack;
	long long health;
	long long total_damage;
};


void solve()
{
	ll hero_attack, hero_health, number_of_monsters;
	cin >> hero_attack >> hero_health >> number_of_monsters;
	vector<monster> v_monster(number_of_monsters, {0, 0, 0});
	for(auto& el: v_monster) cin >> el.attack;
	for(auto& el: v_monster) cin >> el.health;

	ll total_damage = 0, final_blow = 0; 
	for(const auto& el: v_monster) {
		final_blow = max(final_blow, el.attack);
		total_damage += ((el.health + hero_attack - 1)/ hero_attack) * el.attack;
	}


	cout << (total_damage - final_blow < hero_health ? "YES" : "NO") << '\n';
}

int main()
{
	int t;
	cin >> t;
	while(t--)
		solve();
}
