#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long

const int inf = (int) 1e9 + 7;

// This function creates an array that has in the ith position the number of boxes 
// that are already in special position after the ith element (including the ith element).
auto create_suffix_array(const vector<int>& box_position, const vector<int>& special_position) -> vector<int>
{
    int p1 = box_position.size()-1;
    int p2 = special_position.size()-1;
    vector<int> suffix(box_position.size());
    int total_special = 0;
    while(p1 >= 0 && p2 >= 0)
    {
        if(box_position[p1] == special_position[p2]) 
        {
            total_special++;
            suffix[p1] = total_special;
            p1--;
            p2--;
        }
        else if(box_position[p1] > special_position[p2])
        {
            suffix[p1] = total_special;
            p1--;
        }
        else if(box_position[p1] < special_position[p2])
        {
            p2--;
        }
    }

    while(p1 >= 0)
    {
        suffix[p1] = suffix[p1+1];
        p1--;
    }
    return suffix;
}

auto create_suffix_array_ver2(const vector<int>& box_position, const vector<int>& special_position) -> vector<int>
{
    int index = special_position.size()-1;
    vector<int> solution(box_position.size());
    int partials = 0;
    for(int i = box_position.size()-1; i >= 0; i--)
    {
        while(index > 0 && special_position[index] > box_position[i]) index--;
        if(special_position[index] == box_position[i])
        {
            partials++;
        }
        solution[i] = partials;
    }
    return solution;
}

auto create_suffix_array_ver3(const vector<int>& box_position, const vector<int>& special_position) -> vector<int>
{
    int index = special_position.size()-1;
    vector<int> solution;
    int partials = 0;
    transform(box_position.crbegin(), box_position.crend(), back_inserter(solution),
        [&](auto e) {
            while(index > 0 && special_position[index] > e) index--;
            if(special_position[index] == e) partials++;
            return partials;
        });
    reverse(all(solution));
    return solution;
}

auto create_number_of_boxes_array(const vector<int>& box_position, const vector<int>& special_position) -> vector<int>
{
    int index = 0;
    vector<int> solution;
    transform(all(special_position), back_inserter(solution), 
            [&](auto e){ 
                while(index < box_position.size() && e >= box_position[index]) index++;
                return index;
            });
    return solution;
}

auto create_number_of_boxes_array_ver2(const vector<int>& box_position, const vector<int>& special_position) -> vector<int>
{
    int index = 0;
    vector<int> solution;
    for(const auto& el : special_position)
    {
        while(index < box_position.size() && el >= box_position[index]) index++;
        solution.push_back(index);
    }
    return solution;
}

auto create_distance_array(const vector<int>& box_position, const vector<int>& special_position) -> vector<int>
{
    vector<int> solution;
    adjacent_difference(all(special_position), back_inserter(solution));
    return solution;
}

auto find_optimal_pushing_value(const vector<int>& box_position, const vector<int>& special_position) -> int 
{
    // Create suffix array with box_position
    vector<int> suffix = create_suffix_array_ver3(box_position, special_position);
    vector<int> number_of_boxes = create_number_of_boxes_array_ver2(box_position, special_position);
    vector<int> distance_array = create_distance_array(box_position, special_position);
    vector<int> under_block_array(special_position.size());
    // Create block_value array iterating backwards
    for(int i = special_position.size()-1; i >= 0; i-- )
    {
        if(number_of_boxes[i] == 0) return 0;
        if(number_of_boxes[i] < distance_array[i]) under_block_array[i] = 1;
        else 
        {
            under_block_array[i] = 1 + min(number_of_boxes[i] - distance_array[i], under_block_array[min(i+1, (int)special_position.size() - 1)]);
        }
    }
    // Iterate over block_value while doing binary search over the suffix and box_position arrays
    int optimal_total = 0;
    int current_total = 0;
    for(int i = 0; i < special_position.size(); i++)
    {
        // I probably think that the bug is in here
        const int suffix_index = distance(box_position.begin(), upper_bound(all(box_position), special_position[i] + number_of_boxes[i] - 1));
        current_total = under_block_array[i];
        if(suffix_index < suffix.size())
            current_total += suffix[suffix_index];
        optimal_total = max(optimal_total, current_total);
    }
    return optimal_total;
}

void solve()
{
    int n, m; cin >> n >> m;
    vector<int> v1, v2;
    vector<int> magic1, magic2;
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        if(temp < 0) v2.push_back(-temp);
        else v1.push_back(temp);
    }
    for(int i = 0; i < m; i++)
    {
        cin >> temp;
        if(temp < 0) magic2.push_back(-temp);
        else magic1.push_back(temp);
    }
    reverse(all(v2));
    reverse(all(magic2));

    cout << find_optimal_pushing_value(v1, magic1)  + find_optimal_pushing_value(v2, magic2) << '\n';
    // cout << find_optimal_pushing_value(v1, magic1)  << '\n';
    // cout << find_optimal_pushing_value(v2, magic2)  << '\n';
    // cout << '\n';
}

int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--)
        solve();
}
