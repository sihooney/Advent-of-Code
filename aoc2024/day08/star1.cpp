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
            for (int j = i + 1; j < vec.size(); j++)
            {
                int ri = 2 * vec[i].first - vec[j].first, ci = 2 * vec[i].second - vec[j].second;
                int rj = 2 * vec[j].first - vec[i].first, cj = 2 * vec[j].second - vec[i].second;
                if (ri >= 0 && ri < N && ci >= 0 && ci < N && a[ri][ci] != '#')
                {
                    ans++;
                    a[ri][ci] = '#';
                }
                if (rj >= 0 && rj < N && cj >= 0 && cj < N && a[rj][cj] != '#')
                {
                    ans++;
                    a[rj][cj] = '#';
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
