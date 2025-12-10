#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

int main()
{
    ifstream in("day9.txt");
    vector<pair<ll, ll>> a;
    ll x, y, ans{0};
    char c;
    while (in >> x >> c >> y)
    {
        a.emplace_back(pair{x, y});
    }
    in.close();
    for (size_t i{0}; i < a.size() - 1; ++i)
    {
        for (size_t j{i + 1}; j < a.size(); ++j)
        {
            ans = max(ans, (abs(a[i].first - a[j].first) + 1) * (abs(a[i].second - a[j].second) + 1));
        }
    }
    cout << ans << endl;
    return 0;
}
