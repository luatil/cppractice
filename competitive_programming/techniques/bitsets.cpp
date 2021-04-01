#include <bits/stdc++.h>
using namespace std;

// There are N <= 5000 workers. Each is available during some days of this month.
// Find two workers with maximum intersection of ther schedules

auto convert_to_bit_schedule(const vector<vector<int>>& schedule) -> vector<int>
{    
    vector<int> bit_schedule(schedule.size());
    for(int i = 0; i < schedule.size(); i++)
    {
        for(const auto& el: schedule[i])
        {
            bit_schedule[i] += (1 << el);
        }
    }
    return bit_schedule;
}

auto get_maximum_intersection(const vector<int>& bit_array) -> pair<int, int>
{
    pair<int, int> greatest_intersection;
    int max_number_of_intersection = 0;

    // This could be simplified by thinking of an upper triangular product
    for(int i = 0; i < bit_array.size(); i++)
    {
        for(int j = i+1; j < bit_array.size(); j++)
        {
            const int number_of_intersections = __builtin_popcount(bit_array[i] & bit_array[j]);
            if(number_of_intersections > max_number_of_intersection)
            {
                max_number_of_intersection = number_of_intersections;
                greatest_intersection = {i+1, j+1}; // output index starting from 1
            }
        }
    }
    return greatest_intersection;
}

auto maximum_worker_intersection(const vector<vector<int>> & schedule) -> pair<int, int>
{
    vector<int> bit_schedule = convert_to_bit_schedule(schedule);
    return get_maximum_intersection(bit_schedule);
}

void test_maximum_worker_intersection()
{
    vector<vector<int>> schedule = { {2, 3, 5, 6, 8}, 
                                     {2, 4, 5, 8}, 
                                     {1, 2, 10, 12, 14, 16}};
    auto [a, b] = maximum_worker_intersection(schedule);
    if(a == 1 && b == 2)
    {
        cout << "First Test Worked\n";
    }
    else 
    {
        cout << "First Test did not work\n";
        cout << a << ' ' << b << '\n';
    }
}


int main()
{
    test_maximum_worker_intersection();
}