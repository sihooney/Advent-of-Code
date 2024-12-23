#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

const int N = 60;
int a[N][N];
pair<int, int> dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int ans = 0;
set<pair<int, int>> dest;

void dfs(int r, int c, int prev)
{
    if (r >= 0 && r < N && c >= 0 && c < N && a[r][c] == prev + 1)
    {
        if (a[r][c] == 9)
        {
            if (dest.find({r, c}) == dest.end())
            {
                ans++;
            }
            dest.insert({r, c});
            return;
        }
        for (const auto &[dr, dc] : dir)
        {
            dfs(r + dr, c + dc, prev + 1);
        }
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    vector<pair<int, int>> src;
    ifstream input("day10.txt");
    char c;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            input >> c;
            a[i][j] = c - '0';
            if (a[i][j] == 0)
            {
                src.push_back({i, j});
            }
        }
    }
    for (const auto &[r, c] : src)
    {
        dfs(r, c, -1);
        dest.clear();
    }
    cout << ans << endl;

    return 0;
}
