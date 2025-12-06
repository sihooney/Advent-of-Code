#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    ifstream in("day6.txt");
    string s;
    ll ans{0};
    int x;
    vector<vector<int>> a;
    while (getline(in, s))
    {
        istringstream iss(s);
        vector<int> row;
        while (iss >> x)
        {
            row.push_back(x);
        }
        a.push_back(row);
        if (row.empty())
        {
            char op;
            istringstream read_op(s);
            for (size_t c{0}; c < a[0].size(); ++c)
            {
                read_op >> ws >> op;
                ll res{op == '*'};
                for (size_t r{0}; r < a.size() - 1; ++r)
                {
                    if (op == '+')
                    {
                        res += a[r][c];
                    }
                    else
                    {
                        res *= a[r][c];
                    }
                }
                ans += res;
            }
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
