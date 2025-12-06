#include <iostream>
#include <fstream>
#include <set>
#include <cmath>

using namespace std;
using ll = long long;

int main()
{
    ifstream in("day3.txt");
    string s;
    ll ans{0};
    set<int> pos[10];
    while (in >> s)
    {
        for (size_t i{0}; i < s.length(); ++i)
        {
            pos[s[i] - '0'].insert(i);
        }
        int pre{-1};
        for (int n{12}; n > 0; --n)
        {
            for (int digit{9}; digit > 0; --digit)
            {
                if (pos[digit].empty())
                {
                    continue;
                }
                auto it = pos[digit].upper_bound(pre);
                if (it != pos[digit].end() && *it + n <= s.length())
                {
                    pre = *it;
                    ans += digit * (ll)(pow(10, n - 1));
                    break;
                }
            }
        }
        for (int i{0}; i < 10; ++i)
        {
            pos[i] = set<int>();
        }
    }
    cout << ans << endl;
    return 0;
}
