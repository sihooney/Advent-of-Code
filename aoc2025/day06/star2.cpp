#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream in("day6.txt", ios::binary | ios::ate);
    streamsize size{in.tellg()};
    in.seekg(in.beg);
    char *a{new char[size]};
    in.read(a, size);
    in.close();
    int rows{0}, cols;
    for (int i{0};; ++i)
    {
        if (*(a + i) == '\0')
        {
            break;
        }
        rows += *(a + i) == '\n';
    }
    cols = (size - 1) / rows + 1;
    char ch;
    bool add{true};
    vector<int> vals;
    ll total{0};
    for (int j{0}; j < cols; ++j)
    {
        ch = a[(rows - 1) * cols + j];
        if (ch != ' ')
        {
            ll res = !add;
            for (const int x : vals)
            {
                if (add)
                {
                    res += x;
                }
                else
                {
                    res *= x != 0 ? x : 1;
                }
            }
            total += res;
            add = ch == '+';
            vals.clear();
        }
        int n{0}, pow{1}, digit;
        for (int i{rows - 2}; i >= 0; --i)
        {
            digit = a[i * cols + j] - '0';
            if (digit < 0 || digit > 9)
            {
                continue;
            }
            n += digit * pow;
            pow *= 10;
        }
        vals.push_back(n);
    }
    delete[] a;
    a = nullptr;
    cout << total << endl;
    return 0;
}
