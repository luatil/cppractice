#include <bits/stdc++.h>
using namespace std;
int T;

class Solution {
public:
    vector<vector<int>> is_palindrome;
    vector<int> memo;

    vector<vector<int>> get_palindromic_table(string s)
    {
        vector<vector<int>> palindromic_table(s.size(), vector<int>(s.size()));
        for(int offset = 0; offset < s.size(); offset++)
        {
            for(int i = 0; i + offset < s.size(); i++)
            {
                palindromic_table[i][i+offset] = [&](){
                    if(offset == 0) return 1;
                    if(offset == 1) return (int)(s[i] == s[i+offset]);
                    if(s[i] == s[i+offset]) return palindromic_table[i+1][i+offset-1];
                    return 0;
                }();
            }
        }
        return palindromic_table;
    }
    
    void print(vector<vector<int>> table)
    {
        for(auto&row : table) 
        {
            for(auto&el : row)
                cout << el << ' ';
            cout << '\n';
        }
    }
    
    int find_minimum_number_of_partitions(string s) 
    {
        is_palindrome = get_palindromic_table(s);
        fill_n(back_inserter(memo), s.size(), -1);
        memo[0] = 1;
        for(int i = 1; i < memo.size(); i++)
        {
            memo[i] = [&](){
                if(is_palindrome[0][i] == 1) return 1;
                int minimum = 3000;
                for(int k = 0; k < i; k++)
                {
                    if(is_palindrome[k+1][i])
                    {
                        minimum = min(minimum, memo[k] + 1);
                    }
                }
                return minimum;
            }();   
        }        
        return memo[T-1];
    }
};


void test()
{
    Solution s1, s2, s3, s4, s5;
    cout << s1.find_minimum_number_of_partitions("aaxyx") << '\n'; // 2
    cout << s2.find_minimum_number_of_partitions("axa") << '\n'; // 1
    cout << s3.find_minimum_number_of_partitions("xyzyyx") << '\n'; // 4
    cout << s4.find_minimum_number_of_partitions("bbabcbbaab") << '\n'; // 4
    cout << s5.find_minimum_number_of_partitions("a") << '\n'; // 1
}

void solve()
{
    string s; cin >> s;
    Solution s1;
    cout << s1.find_minimum_number_of_partitions(s) << '\n';
}

void drive()
{
    cin >> T;
    int index = 1;
    while(true)
    {
        cout << "Teste " << index << '\n';
        solve();
        cin >> T;
        cout << '\n';
        if(T==0) break;
        index++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    drive();
    //test();
}