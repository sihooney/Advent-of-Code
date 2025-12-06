#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;
using ll = long long;

int main()
{
    ifstream in("day5.txt");
    string line;
    ll l, r, ans{0};
    char c;
    map<ll, bool> diff;
    diff[0] = false;
    while (getline(in, line))
    {
        if (line.empty())
        {
            break;
        }
        istringstream iss(line);
        iss >> l >> c >> r;
        map<ll, bool>::iterator it{--diff.lower_bound(l)};
        bool pre{it->second};
        ++it;
        while (it != diff.end() && it->first <= r)
        {
            pre = it->second;
            it = diff.erase(it);
        }
        diff[l] = true;
        diff[r + 1] = it != diff.end() && it->first == r + 1 ? it->second : pre;
    }
    in.close();
    for (map<ll, bool>::iterator i{diff.begin()}, j{++diff.begin()}; j != diff.end(); ++i, ++j)
    {
        ans += i->second * (j->first - i->first);
    }
    cout << ans << endl;
    return 0;
}
