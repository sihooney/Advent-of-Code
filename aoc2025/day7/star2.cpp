#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
using ll = long long;

int main()
{
    ifstream in("day7.txt");
    string s;
    in >> s;
    ll *cur{new ll[s.size()]{}};
    ll *nxt{new ll[s.size()]{}};
    for (size_t i{0}; i < s.size(); ++i)
    {
        if (s[i] == 'S')
        {
            cur[i] = 1;
            nxt[i] = 1;
        }
    }
    while (in >> s)
    {
        for (size_t i{0}; i < s.size(); ++i)
        {
            if (s[i] == '^')
            {
                nxt[i] = 0;
                if (i > 0)
                {
                    nxt[i - 1] += cur[i];
                }
                if (i + 1 < s.size())
                {
                    nxt[i + 1] += cur[i];
                }
            }
        }
        memcpy(cur, nxt, s.size() * sizeof(ll));
    }
    ll ans{0};
    for (size_t i{0}; i < s.size(); ++i)
    {
        ans += cur[i];
    }
    cout << ans << endl;
    delete[] cur;
    cur = nullptr;
    delete[] nxt;
    nxt = nullptr;
    return 0;
}
