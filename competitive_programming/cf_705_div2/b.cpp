#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < n; i++)
#define ll long long

const int SIZE = 1e5 + 7;

char inversion(char);
bool is_valid_time(string s, int max_hour, int max_minute);
int hour_parser(string s, int max_hour, int max_minute);
int minute_parser(string s, int max_hour, int max_minute);
string from_int_to_string(int hour, int minute, int max_hour, int max_minute);
string next_minute(string s, int max_hour, int max_minute);
string small_int_to_string(int val, int max_val);

char inversion(char c)
{
    if(c == '0') return '0';
    if(c == '1') return '1';
    if(c == '8') return '8';
    if(c == '2') return '5';
    if(c == '5') return '2';
    if(c == ':') return ':';
    return 'x';
}

bool is_valid_time(string s, int max_hour, int max_minute)
{
    if(any_of(all(s), [](auto e){return e == 'x';})) return false;

    int hour = hour_parser(s, max_hour, max_minute);

    if(hour >= max_hour) return false;

    int minute = minute_parser(s, max_hour, max_minute);

    if(minute >= max_minute) return false;

    return true;
}

bool is_valid_reverse_time(string s, int max_hour, int max_minute)
{
    reverse(all(s));
    transform(all(s), s.begin(), inversion);
    return is_valid_time(s, max_hour, max_minute);
}

int hour_parser(string s, int max_hour, int max_minute)
{
    int hour = (s[0] - '0') * 10 + (s[1] - '0');
    return hour;
}

int minute_parser(string s, int max_hour, int max_minute)
{
    int j = 3;
    int minute = (s[0 + j] - '0') * 10 + (s[1 + j] - '0');
    return minute;
}

string small_int_to_string(int val, int max_val)
{
    string s = "";
    if(val == 0) s+= "00";
    else if(val < 10) s += "0" + to_string(val);
    else s += to_string(val);
    return s;
}

string from_int_to_string(int hour, int minute, int max_hour, int max_minute)
{
    string s = small_int_to_string(hour, max(max_hour, max_minute)) + ":" + small_int_to_string(minute, max(max_hour, max_minute));
    return s;
}

string next_minute(string s, int max_hour, int max_minute)
{
    int hour = hour_parser(s, max_hour, max_minute);
    int minute = minute_parser(s, max_hour, max_minute);

    if(minute == max_minute -1 )
    {
        minute = 0;
        if(hour == max_hour - 1)
        {
            hour = 0;
        }
        else 
        {
            hour++;
        }
    }
    else 
    {
        minute++;
    }

    return from_int_to_string(hour, minute, max_hour, max_minute);
}

void solve()
{
    int max_hour, max_minute; cin >> max_hour >> max_minute;
    string s; cin >> s;
    while(!is_valid_reverse_time(s, max_hour, max_minute))
    {
        s = next_minute(s, max_hour, max_minute);
        //cout << s << '\n';
    }
    cout << s << '\n';
}

void test1()
{
    cout << next_minute("00:01", 1, 100) << '\n';
}

int main()
{
    int t; cin >> t;
    while(t--)
        solve();
}
