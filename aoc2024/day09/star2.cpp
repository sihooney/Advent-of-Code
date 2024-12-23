#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct File
{
    int id;
    int len;

    File(int id, int len) : id(id), len(len) {}
};

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    vector<File> a;
    char c;
    int idx = 0;
    ifstream input("day9.txt");
    while (input.get(c))
    {
        c -= '0';
        if (idx % 2 == 0)
        {
            a.push_back(File(idx / 2, c));
        }
        else
        {
            a.push_back(File(-1, c));
        }
        idx++;
    }
    long long ans = 0;
    for (int i = a.size() - 1; i > 0; i--)
    {
        if (a[i].id == -1)
            continue;
        for (int j = 0; j < i; j++)
        {
            if (a[j].id == -1 && a[j].len >= a[i].len)
            {
                int space = a[j].len - a[i].len;
                a[j].id = a[i].id;
                a[j].len = a[i].len;
                a[i].id = -1;
                a.insert(a.begin() + j + 1, File(-1, space));
                break;
            }
        }
    }
    idx = 0;
    for (const File &f : a)
    {
        if (f.id == -1)
        {
            idx += f.len;
            continue;
        }
        for (int j = 0; j < f.len; j++)
        {
            ans += idx * f.id;
            idx++;
        }
    }
    cout << ans << endl;

    return 0;
}
