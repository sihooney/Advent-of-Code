#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bit>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream in("day10.txt");
    string s;
    vector<unsigned int> buttons;
    unsigned int ans{0};
    while (in >> s)
    {
        if (s[0] == '[')
        {
            unsigned int dest{0};
            for (size_t i{1}; i < s.size() - 1; ++i)
            {
                dest |= (s[i] == '#') << (i - 1);
            }
            while (in >> s)
            {
                if (s[0] == '{')
                {
                    break;
                }
                unsigned int x{0};
                for (size_t j{1}; j < s.size() - 1; j += 2)
                {
                    x |= 1 << (s[j] - '0');
                }
                buttons.push_back(x);
            }
            unsigned int req{(unsigned int) (buttons.size()) + 1};
            for (unsigned int mask{0}, state{0}; mask < (1 << buttons.size()); ++mask)
            {
                for (size_t k{0}; k < buttons.size(); ++k)
                {
                    if (mask & (1 << k))
                    {
                        state ^= buttons[k];
                    }
                }
                if (state == dest)
                {
                    req = popcount(mask) < req ? popcount(mask) : req;
                }
                state = 0;
            }
            ans += req;
            buttons.clear();
        }
    }
    cout << ans << endl;
    return 0;
}
