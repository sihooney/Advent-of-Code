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
        dx = (c == 'R') ? dx : -dx;
        x = ((x + dx) % 100 + 100) % 100;
        cnt += !x;
    }
    cout << cnt << endl;
    return 0;
}
