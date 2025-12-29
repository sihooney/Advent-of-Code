#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

constexpr size_t encode(const char *s)
{
    return (s[0] - 'a') * 26 * 26 + (s[1] - 'a') * 26 + s[2] - 'a';
}

constexpr size_t MAX{encode("zzz")};
constexpr size_t SRC{encode("svr")};
constexpr size_t DAC{encode("dac")};
constexpr size_t FFT{encode("fft")};
constexpr size_t DEST(encode("out"));
vector<size_t> adj[MAX + 1];
int dp[MAX + 1]{};

size_t dfs(size_t u, size_t dest)
{
    if (u == dest)
    {
        return 1;
    }
    if (dp[u] != -1)
    {
        return dp[u];
    }
    size_t cnt{0};
    for (const size_t &v : adj[u])
    {
        cnt += dfs(v, dest);
    }
    return dp[u] = cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream in("day11.txt");
    char s[4];
    size_t node;
    while (in >> s)
    {
        if (s[3] == ':')
        {
            node = encode(s);
        }
        else
        {
            adj[node].push_back(encode(s));
        }
    }
    size_t paths[6][3]{{SRC, DAC, 0}, {DAC, FFT, 0}, {FFT, DEST, 0}, {SRC, FFT, 0}, {FFT, DAC, 0}, {DAC, DEST, 0}};
    for (size_t i{0}; i < 6; ++i)
    {
        memset(dp, -1, sizeof(dp));
        dfs(paths[i][0], paths[i][1]);
        paths[i][2] = dp[paths[i][0]];
    }
    cout << paths[0][2] * paths[1][2] * paths[2][2] + paths[3][2] * paths[4][2] * paths[5][2] << endl;
    return 0;
}
