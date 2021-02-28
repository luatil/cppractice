#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, a, n) for(int i = a; i < n; i++)

template <typename T> 
void print(T v)
{
	for(const auto& el: v) cout << el << " ";
	cout << "\n";
}

struct operation 
{
	int left, right, value;
};

int main()
{
	int number_of_elements, number_of_operations, number_of_queries;
	cin >> number_of_elements >> number_of_operations >> number_of_queries;

	vector<long long> elements(number_of_elements+2);
	REP(i, 1, number_of_elements+1)
		cin >> elements[i];

	vector<operation> operations(number_of_operations+2);
	REP(i, 1, number_of_operations+1)
		cin >> operations[i].left >> operations[i].right >> operations[i].value;

	vector<long long> operation_ranges(number_of_operations+2);
	int first_operation, last_operation;
	REP(i, 0, number_of_queries)
	{
		cin >> first_operation >> last_operation;	
		operation_ranges[first_operation]++;
		operation_ranges[last_operation + 1]--;
	}

	vector<long long> number_of_times_operation_is_applied(number_of_operations+2);
	partial_sum(all(operation_ranges), number_of_times_operation_is_applied.begin());
	//print(number_of_times_operation_is_applied);

	adjacent_difference(all(elements), elements.begin());

	for(int i = 1; i <= number_of_operations; ++i)
	{
		int start_point, end_point;
		long long value;
		start_point = operations[i].left;
		end_point = operations[i].right;
		value = operations[i].value * number_of_times_operation_is_applied[i];
		elements[start_point] += value;
		elements[end_point + 1] -= value;
	}

	partial_sum(all(elements), elements.begin());


	for(int i = 1; i <= number_of_elements; ++i)
		cout << elements[i] << " ";
	cout << "\n";
	//print(elements);

}
