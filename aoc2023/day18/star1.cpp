#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

unordered_map<char, pair<int, int>> dir = {{'L', {-1, 0}}, {'R', {1, 0}}, {'U', {0, 1}}, {'D', {0, -1}}};
vector<pair<int, int>> cords;
vector<vector<bool>> grid;
pair<int, int> moves[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void dfs(int r, int c)
{
    if (grid[r][c])
    {
        return;
    }
    grid[r][c] = true;
    for (auto [dr, dc] : moves)
    {
        dfs(r + dr, c + dc);
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    ifstream input("day18.txt");
    char c;
    int n;
    string color;
    int upbound = 0, lowbound = 0, leftbound = 0, rightbound = 0, x = 0, y = 0;
    cords.push_back({0, 0});
    for (int i = 0; i < 708; i++)
    {
        input >> c >> n >> color;
        for (int j = 0; j < n; j++)
        {
            x += dir[c].first;
            y += dir[c].second;
            cords.push_back({x, y});
        }
        upbound = max(upbound, y);
        lowbound = min(lowbound, y);
        leftbound = min(leftbound, x);
        rightbound = max(rightbound, x);
    }
    input.close();
    grid.resize(upbound - lowbound + 1, vector<bool>(rightbound - leftbound + 1));
    for (auto [x, y] : cords)
    {
        grid[y - lowbound][x - leftbound] = true;
    }
    for (int i = 0; i < grid[0].size(); i++)
    {
        if (grid[1][i])
        {
            dfs(1, i + 1);
            break;
        }
    }
    int ans = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            ans += grid[i][j];
        }
    }
    cout << ans << endl;

    return 0;
}
