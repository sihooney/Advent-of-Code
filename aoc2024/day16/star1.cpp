#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const int N = 141;
char a[N][N];
int dp[N][N][4];

void dfs(int r, int c, int d)
{
    for (int nd = 0; nd < 4; nd++)
    {
        int nr = r + dir[nd][0], nc = c + dir[nd][1];
        if (nr >= 0 && nr < N && nc >= 0 && nc < N && a[nr][nc] != '#')
        {
            int score = dp[r][c][d] + 1 + (nd != d ? 1000 : 0);
            if (score < dp[nr][nc][nd])
            {
                dp[nr][nc][nd] = score;
                dfs(nr, nc, nd);
            }
        }
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    fill(&a[0][0], &a[0][0] + N * N, '#');
    fill(&dp[0][0][0], &dp[0][0][0] + N * N * 4, 1e9);
    ifstream input("day16.txt");
    int srcR, srcC, destR, destC;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            input >> a[i][j];
            srcR = a[i][j] == 'S' ? i : srcR;
            srcC = a[i][j] == 'S' ? j : srcC;
            destR = a[i][j] == 'E' ? i : destR;
            destC = a[i][j] == 'E' ? j : destC;
        }
    }
    dp[srcR][srcC][3] = 0;
    dfs(srcR, srcC, 3);
    int ans = 1e9;
    for (int i = 0; i < 4; i++)
    {
        ans = dp[destR][destC][i] < ans ? dp[destR][destC][i] : ans;
    }
    cout << ans << endl;

    return 0;
}
