#include <iostream>
#include <fstream>
#include <set>

using namespace std;

const int N = 140;
char a[N][N];
pair<int, int> dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
set<pair<int, int>> vis;
int area = 0, perimeter = 0, ans = 0;

void dfs(int i, int j, char c)
{
    if (i < 0 || i >= N || j < 0 || j >= N)
    {
        perimeter++;
        return;
    }
    if (vis.count({i, j}))
    {
        return;
    }
    if (a[i][j] != c)
    {
        perimeter++;
        return;
    }
    area++;
    vis.insert({i, j});
    for (const auto &[di, dj] : dir)
    {
        dfs(i + di, j + dj, c);
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    ifstream input("day12.txt");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            input >> a[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (a[i][j] != '#')
            {
                dfs(i, j, a[i][j]);
                ans += area * perimeter;
                for (const auto &[r, c] : vis)
                {
                    a[r][c] = '#';
                }
                vis.clear();
                area = 0;
                perimeter = 0;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
