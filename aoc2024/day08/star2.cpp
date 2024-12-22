#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    const int N = 50;
    char a[N][N];
    unordered_map<char, vector<pair<int, int>>> map;
    int ans = 0;
    ifstream input("day8.txt");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            input >> a[i][j];
            if (a[i][j] != '.')
            {
                map[a[i][j]].push_back({i, j});
            }
        }
    }
    for (const auto &[key, vec] : map)
    {
        for (int i = 0; i < vec.size() - 1; i++)
        {
            int r = vec[i].first, c = vec[i].second;
            for (int j = i + 1; j < vec.size(); j++)
            {
                a[r][c] = '#';
                int nr = r, nc = c;
                int dr = r - vec[j].first, dc = c - vec[j].second;
                while (true)
                {
                    nr -= dr;
                    nc -= dc;
                    if (nr >= 0 && nr < N && nc >= 0 && nc < N)
                    {
                        if (a[nr][nc] != '#')
                        {
                            a[nr][nc] = '#';
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                nr = r, nc = c;
                while (true)
                {
                    nr += dr;
                    nc += dc;
                    if (nr >= 0 && nr < N && nc >= 0 && nc < N)
                    {
                        if (a[nr][nc] != '#')
                        {
                            a[nr][nc] = '#';
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ans += a[i][j] == '#';
        }
    }
    cout << ans << endl;

    return 0;
}
