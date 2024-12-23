#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    vector<int> a;
    char c;
    int i = 0;
    ifstream input("day9.txt");
    while (input.get(c))
    {
        c -= '0';
        if (i % 2 == 0)
        {
            for (int j = 0; j < c; j++)
            {
                a.push_back(i / 2);
            }
        }
        else
        {
            for (int j = 0; j < c; j++)
            {
                a.push_back(-1);
            }
        }
        i++;
    }
    int left = 0, right = a.size() - 1;
    long long ans = 0;
    while (left < right)
    {
        if (a[right] == -1)
        {
            right--;
            continue;
        }
        if (a[left] != -1)
        {
            left++;
            continue;
        }
        a[left] = a[right];
        a[right] = -1;
    }
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == -1)
            break;
        ans += a[i] * i;
    }
    cout << ans << endl;

    return 0;
}
