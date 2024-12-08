#include <iostream>
#include <fstream>

using namespace std;

const int N = 130;
char a[N][N];
int ans = 0;

void dfs(int r, int c, int dr, int dc)
{
    if (r < 0 || r >= 130 || c < 0 || c >= 130)
    {
        return;
    }
    if (a[r][c] != '#')
    {
        if (a[r][c] == '.')
        {
            ans++;
            a[r][c] = '*';
        }
        dfs(r + dr, c + dc, dr, dc);
    }
    else
    {
        if (dr == -1)
        {
            dfs(r + 1, c + 1, 0, 1);
        }
        else if (dr == 1)
        {
            dfs(r - 1, c - 1, 0, -1);
        }
        else if (dc == -1)
        {
            dfs(r - 1, c + 1, -1, 0);
        }
        else
        {
            dfs(r + 1, c - 1, 1, 0);
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
            input >> a[i][j];
            if (a[i][j] == '^')
            {
                srcR = i;
                srcC = j;
                a[i][j] = '.';
            }
        }
    }
    dfs(srcR, srcC, -1, 0);
    cout << ans << endl;

    return 0;
}
