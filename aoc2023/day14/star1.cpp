#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream file("day14.txt");
    int size = 100;
    char a[size][size];
    char strip;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            file.get(a[i][j]);
        }
        file.get(strip);
    }
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
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (a[i][j] == 'O')
            {
                ans += size - i;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
