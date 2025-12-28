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
constexpr size_t SRC{encode("you")};
constexpr size_t DEST(encode("out"));
vector<size_t> adj[MAX + 1];
int dp[MAX + 1]{};

size_t dfs(size_t u)
{
    if (u == DEST)
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
        cnt += dfs(v);
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
    memset(dp, -1, sizeof(dp));
    dfs(SRC);
    cout << dp[SRC] << endl;
    return 0;
}
