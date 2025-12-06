#include <iostream>
#include <fstream>

using namespace std;
using ll = long long;

int main()
{
    ifstream in("day2.txt");
    char c;
    ll a, b, ans{0};
    while (in >> a >> c >> b)
    {
        for (ll x{a}; x <= b; ++x)
        {
            string s{to_string(x)};
            ans += (s.substr(0, s.length() / 2) == s.substr(s.length() / 2)) * x;
        }
        in >> c;
    }
    cout << ans << endl;
    return 0;
}
