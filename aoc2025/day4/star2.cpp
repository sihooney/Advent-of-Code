#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<char>> a;
int dir[8][2]{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
unordered_set<int> s;

int offset()
{
    return max(a.size(), a[0].size()) + 1;
}

void solve(int &n)
{
    bool removed{false};
    for (auto it = s.begin(); it != s.end();)
    {
        int r{*it / offset()}, c{*it % offset()}, cnt{0};
        for (const auto &[dr, dc] : dir)
        {
            if (s.count((r + dr) * offset() + c + dc))
            {
                ++cnt;
            }
        }
        if (cnt < 4)
        {
            it = s.erase(it);
            ++n;
            removed = true;
        }
        else
        {
            ++it;
        }
    }
    if (!removed)
    {
        return;
    }
    solve(n);
}

int main()
{
    ifstream in("day4.txt");
    string line;
    while (in >> line)
    {
        a.emplace_back(line.begin(), line.end());
    }
    in.close();
    s.reserve(a.size() * a[0].size());
    for (size_t r{0}; r < a.size(); ++r)
    {
        for (size_t c{0}, cnt{0}; c < a[r].size(); ++c, cnt = 0)
        {
            if (a[r][c] == '@')
            {
                s.insert(r * offset() + c);
            }
        }
    }
    int total{0};
    solve(total);
    cout << total << endl;
    return 0;
}
