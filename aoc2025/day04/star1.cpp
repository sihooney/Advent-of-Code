#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream in("day4.txt");
    string s;
    vector<vector<char>> a;
    int ans{0};
    int dir[8][2]{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    while (in >> s)
    {
        a.emplace_back(s.begin(), s.end());
    }
    in.close();
    for (int r{0}; r < a.size(); ++r)
    {
        for (int c{0}, cnt{0}; c < a[r].size(); ++c, cnt = 0)
        {
            if (a[r][c] == '.')
            {
                continue;
            }
            for (const auto &[dr, dc] : dir)
            {
                if (r + dr < 0 || r + dr >= a.size() || c + dc < 0 || c + dc >= a[r].size())
                {
                    continue;
                }
                cnt += a[r + dr][c + dc] == '@';
            }
            ans += cnt < 4;
        }
    }
    cout << ans << endl;
    return 0;
}
