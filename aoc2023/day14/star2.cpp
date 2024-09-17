#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int size = 100;
const int N = 1000000000;
char a[size][size];
vector<string> states;

void north()
{
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (a[i][j] == 'O')
            {
                bool top = true;
                a[i][j] = '.';
                for (int k = i - 1; k >= 0; k--)
                {
                    if (a[k][j] == 'O' || a[k][j] == '#')
                    {
                        a[k + 1][j] = 'O';
                        top = false;
                        break;
                    }
                }
                if (top)
                {
                    a[0][j] = 'O';
                }
            }
        }
    }
}

void south()
{
    for (int i = size - 1; i >= 0; i--)
    {
        for (int j = 0; j < size; j++)
        {
            if (a[i][j] == 'O')
            {
                bool bot = true;
                a[i][j] = '.';
                for (int k = i + 1; k < size; k++)
                {
                    if (a[k][j] == 'O' || a[k][j] == '#')
                    {
                        a[k - 1][j] = 'O';
                        bot = false;
                        break;
                    }
                }
                if (bot)
                {
                    a[size - 1][j] = 'O';
                }
            }
        }
    }
}

void west()
{
    for (int j = 1; j < size; j++)
    {
        for (int i = 0; i < size; i++)
        {
            if (a[i][j] == 'O')
            {
                bool left = true;
                a[i][j] = '.';
                for (int k = j - 1; k >= 0; k--)
                {
                    if (a[i][k] == 'O' || a[i][k] == '#')
                    {
                        a[i][k + 1] = 'O';
                        left = false;
                        break;
                    }
                }
                if (left)
                {
                    a[i][0] = 'O';
                }
            }
        }
    }
}

void east()
{
    for (int j = size - 1; j >= 0; j--)
    {
        for (int i = 0; i < size; i++)
        {
            if (a[i][j] == 'O')
            {
                bool right = true;
                a[i][j] = '.';
                for (int k = j + 1; k < size; k++)
                {
                    if (a[i][k] == 'O' || a[i][k] == '#')
                    {
                        a[i][k - 1] = 'O';
                        right = false;
                        break;
                    }
                }
                if (right)
                {
                    a[i][size - 1] = 'O';
                }
            }
        }
    }
}

int main()
{
    ifstream file("day14.txt");
    char strip;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            file.get(a[i][j]);
        }
        file.get(strip);
    }
    int remainder;
    vector<string>::iterator cycle_start;
    for (int x = 1; x <= N; x++)
    {
        north();
        west();
        south();
        east();
        string s;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                s += a[i][j];
            }
        }
        vector<string>::iterator it = find(states.begin(), states.end(), s);
        if (it == states.end())
        {
            states.push_back(s);
        }
        else
        {
            cycle_start = it;
            int len = distance(cycle_start, states.end());
            remainder = (N - (distance(states.begin(), cycle_start) + 1)) % len;
            break;
        }
    }
    advance(cycle_start, remainder);
    string res = *cycle_start;
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (res[i * size + j] == 'O')
            {
                ans += size - i;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
