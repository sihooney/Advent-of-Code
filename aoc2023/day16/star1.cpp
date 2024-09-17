#include <iostream>
#include <fstream>
#include <set>
#include <vector>

using namespace std;

const int MAXN = 110;
char a[MAXN + 1][MAXN + 1];
vector<vector<set<pair<int, int>>>> pre(MAXN + 1, vector<set<pair<int, int>>>(MAXN + 1));
int ans = 0;

void dfs(int r, int c, int dr, int dc)
{
    if (r < 1 || c < 1 || r > MAXN || c > MAXN)
    {
        return;
    }
    if (pre[r][c].count({dr, dc}))
    {
        return;
    }
    else if (pre[r][c].empty())
    {
        ans++;
    }
    pre[r][c].insert({dr, dc});
    if (a[r][c] == '.')
    {
        dfs(r + dr, c + dc, dr, dc);
    }
    if (a[r][c] == '/')
    {
        if (dr == 1)
        {
            dfs(r, c - 1, 0, -1);
        }
        else if (dr == -1)
        {
            dfs(r, c + 1, 0, 1);
        }
        else if (dc == 1)
        {
            dfs(r - 1, c, -1, 0);
        }
        else if (dc == -1)
        {
            dfs(r + 1, c, 1, 0);
        }
    }
    else if (a[r][c] == '\\')
    {
        if (dr == 1)
        {
            dfs(r, c + 1, 0, 1);
        }
        else if (dr == -1)
        {
            dfs(r, c - 1, 0, -1);
        }
        else if (dc == 1)
        {
            dfs(r + 1, c, 1, 0);
        }
        else if (dc == -1)
        {
            dfs(r - 1, c, -1, 0);
        }
    }
    else if (a[r][c] == '|')
    {
        if (dr == 1)
        {
            dfs(r + 1, c, 1, 0);
        }
        else if (dr == -1)
        {
            dfs(r - 1, c, -1, 0);
        }
        else
        {
            dfs(r + 1, c, 1, 0);
            dfs(r - 1, c, -1, 0);
        }
    }
    else if (a[r][c] == '-')
    {
        if (dc == 1)
        {
            dfs(r, c + 1, 0, 1);
        }
        else if (dc == -1)
        {
            dfs(r, c - 1, 0, -1);
        }
        else
        {
            dfs(r, c + 1, 0, 1);
            dfs(r, c - 1, 0, -1);
        }
    }
}

int main()
{
    ifstream input("day16.txt");
    char strip;
    for (int i = 1; i <= MAXN; i++)
    {
        for (int j = 1; j <= MAXN; j++)
        {
            input.get(a[i][j]);
        }
        input.get(strip);
    }
    input.close();
    dfs(1, 1, 0, 1);
    cout << ans << endl;
    return 0;
}
