#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
using ll = long long;

ll val, n, ans = 0;
char colon;
vector<ll> a;

ll compute(int bitmask, vector<ll> b)
{
    for (int i = 0; i < b.size() - 1; i++)
    {
        if (bitmask & (1 << i))
        {
            b[i + 1] *= b[i];
        }
        else
        {
            b[i + 1] += b[i];
        }
    }
    return b[b.size() - 1];
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    ifstream input("day7.txt");
    while (input >> val >> colon)
    {
        while (input.peek() != '\n' && input >> n)
        {
            a.push_back(n);
        }
        for (ll i = 0; i < 1 << (a.size() - 1); i++)
        {
            if (compute(i, a) == val)
            {
                ans += val;
                break;
            }
        }
        a.clear();
    }
    cout << ans << endl;

    return 0;
}
