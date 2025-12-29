#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream in("day1.txt");
    char c;
    int x{50}, dx, cnt{0};
    while (in >> c)
    {
        in >> dx;
        cnt += dx > 0 ? dx / 100 : -dx / 100;
        if (c == 'R')
        {
            x += dx % 100;
            cnt += x > 99;
            x %= 100;
        }
        else
        {
            x -= dx % 100;
            cnt += x < 1 && x + dx % 100;
            x += x < 0 ? 100 : 0;
        }
    }
    cout << cnt << endl;
    return 0;
}
