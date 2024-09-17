#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

char grid[141][141];
vector<pair<int, int>> galaxies;
ll col_shift[141];
ll row_shift[141];

int main()
{
    ifstream f;
    f.open("day11.txt");
    for (int i = 1; i <= 140; i++)
    {
        for (int j = 1; j <= 140; j++)
        {
            f >> grid[i][j];
            if (grid[i][j] == '#')
            {
                galaxies.push_back({i, j});
            }
        }
    }
    for (int i = 1; i <= 140; i++)
    {
        bool col_empty = true, row_empty = true;
        for (int j = 1; j <= 140; j++)
        {
            if (grid[i][j] == '#')
            {
                row_empty = false;
            }
            if (grid[j][i] == '#')
            {
                col_empty = false;
            }
        }
        col_shift[i] = col_empty ? col_shift[i - 1] + 999999 : col_shift[i - 1];
        row_shift[i] = row_empty ? row_shift[i - 1] + 999999 : row_shift[i - 1];
    }
    for (auto &[r, c] : galaxies)
    {
        r += row_shift[r];
        c += col_shift[c];
    }
    ll ans = 0;
    for (int i = 0; i < galaxies.size() - 1; i++)
    {
        for (int j = i + 1; j < galaxies.size(); j++)
        {
            ans += abs(galaxies[i].first - galaxies[j].first) + abs(galaxies[i].second - galaxies[j].second);
        }
    }
    cout << ans << endl;

    return 0;
}
