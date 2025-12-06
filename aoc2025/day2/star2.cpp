#include <iostream>
#include <fstream>

using namespace std;
using ll = long long;

bool is_invalid(string s)
{
    for (size_t len{s.length() / 2}; len >= 1; --len)
    {
        if (s.length() % len != 0)
        {
            continue;
        }
        bool repeat{true};
        for (size_t i{0}; i < len; ++i)
        {
            if (!repeat)
            {
                break;
            }
            for (size_t j{i + len}; j < s.length(); j += len)
            {
                if (s[j] != s[i])
                {
                    repeat = false;
                    break;
                }
            }
        }
        if (repeat)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ifstream in("day2.txt");
    char c;
    ll a, b, ans{0};
    while (in >> a >> c >> b)
    {
        for (ll x{a}; x <= b; ++x)
        {
            ans += is_invalid(to_string(x)) * x;
        }
        in >> c;
    }
    cout << ans << endl;
    return 0;
}
