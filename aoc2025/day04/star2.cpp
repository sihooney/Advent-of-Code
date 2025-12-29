#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<char>> a;
int dir[8][2]{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
unordered_set<int> s;
int ans{0};

int offset()
{
    return max(a.size(), a[0].size()) + 1;
}

void solve()
{
    bool removed{false};
    for (unordered_set<int>::iterator it{s.begin()}; it != s.end();)
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
            ++ans;
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
    solve();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream in("day4.txt");
    string line;
    while (in >> line)
    {
        a.emplace_back(line.begin(), line.end());
    }
    in.close();
    s.reserve(a.size() * a[0].size());
    for (int r{0}; r < a.size(); ++r)
    {
        for (int c{0}, cnt{0}; c < a[r].size(); ++c, cnt = 0)
        {
            if (a[r][c] == '@')
            {
                s.insert(r * offset() + c);
            }
        }
    }
    solve();
    cout << ans << endl;
    return 0;
}
