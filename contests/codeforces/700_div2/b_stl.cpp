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
	for(auto& el: v_monster) el.total_damage = ((el.health + hero_attack - 1) / hero_attack)  * el.attack;
 
	
	// Super carefull with the accumulator type, there 0 was giving me the wrong result 
	const ll total_damage = accumulate(all(v_monster), 0LL, 
			                  [](ll total, auto monster) { return total + monster.total_damage; });
 
	const ll final_blow = (*max_element(all(v_monster), 
									   [](auto a, auto b) { return a.attack < b.attack; })).attack;
 
	cout << (total_damage - final_blow < hero_health ? "YES" : "NO") << '\n';
}
 
int main()
{
	int t;
	cin >> t;
	while(t--)
		solve();
}
