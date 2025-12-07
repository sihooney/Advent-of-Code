#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
    ifstream in("day7.txt");
    string s;
    in >> s;
    bool *cur{new bool[s.size()]{}};
    bool *nxt{new bool[s.size()]{}};
    for (size_t i{0}; i < s.size(); ++i)
    {
        if (s[i] == 'S')
        {
            cur[i] = true;
            break;
        }
    }
    int ans{0};
    while (in >> s)
    {
        for (size_t i{0}; i < s.size(); ++i)
        {
            if (cur[i])
            {
                if (s[i] != '^')
                {
                    nxt[i] = cur[i];
                    continue;
                }
                ++ans;
                nxt[i] = false;
                if (i > 0)
                {
                    nxt[i - 1] = true;
                }
                if (i + 1 < s.size())
                {
                    nxt[i + 1] = true;
                }
            }
        }
        memcpy(cur, nxt, s.size() * sizeof(bool));
    }
    delete[] cur;
    cur = nullptr;
    delete[] nxt;
    nxt = nullptr;
    cout << ans << endl;
    return 0;
}
