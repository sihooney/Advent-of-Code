#include <iostream>
#include <unordered_map>
#include <fstream>

using namespace std;

char grid[143][143];
pair<int, int> dir[8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
unordered_map<char, pair<pair<int, int>, pair<int, int>>> in_pipe = {
    {'|', {{-1, 0}, {1, 0}}},
    {'-', {{0, -1}, {0, 1}}},
    {'L', {{1, 0}, {0, -1}}},
    {'J', {{1, 0}, {0, 1}}},
    {'7', {{-1, 0}, {0, 1}}},
    {'F', {{-1, 0}, {0, -1}}},
};
pair<int, int> src;
pair<int, int> cur;
pair<int, int> prevmv;
int dist = 1;

void move()
{
    char c = grid[cur.first][cur.second];
    pair<int, int> dir;
    if (prevmv == in_pipe[c].first)
    {
        dir = in_pipe[c].second;
    }
    else
    {
        dir = in_pipe[c].first;
    }
    prevmv.first = dir.first;
    prevmv.second = dir.second;
    if (dir.first == 1)
    {
        cur.first -= 1;
        prevmv.first = -1;
    }
    else if (dir.first == -1)
    {
        cur.first += 1;
        prevmv.first = 1;
    }
    else if (dir.second == 1)
    {
        cur.second -= 1;
        prevmv.second = -1;
    }
    else if (dir.second == -1)
    {
        cur.second += 1;
        prevmv.second = 1;
    }
    dist += 1;
}

int main()
{
    ifstream input;
    input.open("day10.txt");
    char strip;
    for (int i = 1; i <= 140; i++)
    {
        for (int j = 1; j <= 140; j++)
        {
            input.get(grid[i][j]);
            if (grid[i][j] == 'S')
            {
                src = {i, j};
            }
        }
        input.get(strip);
    }
    input.close();
    for (auto d : dir)
    {
        int nr = src.first + d.first, nc = src.second + d.second;
        char c = grid[nr][nc];
        if (c != '.' && (d == in_pipe[c].first || d == in_pipe[c].second))
        {
            cur = {nr, nc};
            prevmv = d;
            break;
        }
    }
    while (cur != src)
    {
        move();
    }
    dist--;
    if (dist % 2 == 0)
    {
        cout << dist / 2 << endl;
    }
    else
    {
        cout << dist / 2 + 1 << endl;
    }

    return 0;
}
