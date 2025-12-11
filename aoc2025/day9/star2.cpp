#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

inline bool contains(int px, int py, int x1, int y1, int x2, int y2)
{
    return px > min(x1, x2) && px < max(x1, x2) && py > min(y1, y2) && py < max(y1, y2);
}

inline int sgn(ll n)
{
    return (n > 0) - (n < 0);
}

int main()
{
    ifstream in("day9.txt");
    vector<pair<ll, ll>> pts;
    vector<pair<ll, pair<size_t, size_t>>> areas;
    ll xi, yi;
    char c;
    while (in >> xi >> c >> yi)
    {
        pts.push_back({xi, yi});
    }
    in.close();
    for (size_t i{0}; i < pts.size() - 1; ++i)
    {
        for (size_t j{i + 1}; j < pts.size(); ++j)
        {
            areas.push_back({(abs(pts[i].first - pts[j].first) + 1) * (abs(pts[i].second - pts[j].second) + 1), {i, j}});
        }
    }
    sort(areas.begin(), areas.end(), [](const auto &a, const auto &b)
         { return a.first > b.first; });
    pts.push_back(pts[0]);
    for (auto &[a, corners] : areas)
    {
        const auto &[x1, y1]{pts[corners.first]};
        const auto &[x2, y2]{pts[corners.second]};
        bool intersect{false};
        for (size_t i{1}; i < pts.size(); ++i)
        {
            ll prev_x{pts[i - 1].first}, prev_y{pts[i - 1].second}, cur_x{pts[i].first}, cur_y{pts[i].second};
            int dx{sgn(cur_x - prev_x)}, dy{sgn(cur_y - prev_y)};
            intersect |= contains(prev_x + dx, prev_y + dy, x1, y1, x2, y2) ||
                         contains(cur_x - dx, cur_y - dy, x1, y1, x2, y2) ||
                         dx == 0 && prev_x > min(x1, x2) && prev_x < max(x1, x2) && min(prev_y, cur_y) <= min(y1, y2) && max(prev_y, cur_y) >= max(y1, y2) ||
                         dy == 0 && prev_y > min(y1, y2) && prev_y < max(y1, y2) && min(prev_x, cur_x) <= min(x1, x2) && max(prev_x, cur_x) >= max(x1, x2);
            if (intersect)
            {
                break;
            }
        }
        if (!intersect)
        {
            int cnt_mid{0}, cnt_x1_y2{0}, cnt_x2_y1{0};
            double mid_x{(x1 + x2) / 2 + 0.5}, mid_y{(y1 + y2) / 2 + 0.5}, dx{0.5 * sgn(x2 - x1)}, dy{0.5 * sgn(y2 - y1)};
            for (size_t i{1}; i < pts.size(); ++i)
            {
                ll prev_x{pts[i - 1].first}, prev_y{pts[i - 1].second}, cur_x{pts[i].first}, cur_y{pts[i].second};
                cnt_mid += prev_x == cur_x && cur_x > mid_x && mid_y > min(prev_y, cur_y) && mid_y < max(prev_y, cur_y);
                cnt_x1_y2 += prev_x == cur_x && cur_x > x1 + dx && y2 - dy > min(prev_y, cur_y) && y2 - dy < max(prev_y, cur_y);
                cnt_x2_y1 += prev_x == cur_x && cur_x > x2 - dx && y1 + dy > min(prev_y, cur_y) && y1 + dy < max(prev_y, cur_y);
            }
            if (cnt_mid % 2 && cnt_x1_y2 % 2 && cnt_x2_y1 % 2)
            {
                cout << a << endl;
                break;
            }
        }
    }
    return 0;
}
