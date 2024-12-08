#include <iostream>
#include <fstream>
#include <set>
#include <vector>

using namespace std;

const int N = 130;
vector<vector<char>> grid(N, vector<char>(N));
set<pair<pair<int, int>, pair<int, int>>> pre;
int ans = 0;

bool dfs(int r, int c, int dr, int dc)
{
    if (r < 0 || r >= 130 || c < 0 || c >= 130)
    {
        return false;
    }
    if (grid[r][c] != '#')
    {
        if (pre.count({{r, c}, {dr, dc}}))
        {
            return true;
        }
        pre.insert({{r, c}, {dr, dc}});
        return dfs(r + dr, c + dc, dr, dc);
    }
    else
    {
        if (dr == -1)
        {
            return dfs(r + 1, c + 1, 0, 1);
        }
        else if (dr == 1)
        {
            return dfs(r - 1, c - 1, 0, -1);
        }
        else if (dc == -1)
        {
            return dfs(r - 1, c + 1, -1, 0);
        }
        else
        {
            return dfs(r + 1, c - 1, 1, 0);
        }
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    ifstream input("day6.txt");
    int srcR, srcC;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            input >> grid[i][j];
            if (grid[i][j] == '^')
            {
                srcR = i;
                srcC = j;
                grid[i][j] = '.';
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << i << ' ' << j << endl;
            if (grid[i][j] != '#')
            {
                grid[i][j] = '#';
                ans += dfs(srcR, srcC, -1, 0);
                grid[i][j] = '.';
            }
            pre.clear();
        }
    }
    cout << ans << endl;

    return 0;
}
