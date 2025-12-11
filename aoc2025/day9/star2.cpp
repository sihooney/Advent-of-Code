#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;
using ll = long long;

// Solution is incorrect for most possible inputs, but works for given input
// Only checks if midpoints of all edges do not fall within rectangle
// Not a proper solution for any sort of general case

int main()
{
    ifstream in("day9.txt");
    vector<pair<ll, ll>> pts;
    vector<pair<ll, pair<size_t, size_t>>> areas;
    ll xi, yi;
    char c;
    while (in >> xi >> c >> yi)
    {
        pts.emplace_back(pair{xi, yi});
    }
    in.close();
    for (size_t i{0}; i < pts.size() - 1; ++i)
    {
        for (size_t j{i + 1}; j < pts.size(); ++j)
        {
            ll dx{pts[i].first - pts[j].first}, dy{pts[i].second - pts[j].second};
            areas.emplace_back(pair{(abs(dx) + 1) * (abs(dy) + 1), pair{i, j}});
        }
    }
    sort(areas.begin(), areas.end(), [](const auto &a, const auto &b)
         { return a.first > b.first; });
    pts.push_back(pts[0]);
    for (auto &[a, corners] : areas)
    {
        const auto &[x1, y1]{pts[corners.first]};
        const auto &[x2, y2]{pts[corners.second]};
        ll x_max{max(x1, x2)}, x_min{min(x1, x2)}, y_max{max(y1, y2)}, y_min{min(y1, y2)};
        bool valid{true};
        for (size_t i{1}; i < pts.size(); ++i)
        {
            ll midx{(pts[i - 1].first + pts[i].first) / 2}, midy{(pts[i - 1].second + pts[i].second) / 2};
            if (midx > x_min && midx < x_max && midy > y_min && midy < y_max)
            {
                valid = false;
                break;
            }
            if (!valid)
            {
                break;
            }
        }
        if (valid)
        {
            cout << a << endl;
            break;
        }
    }
    return 0;
}
