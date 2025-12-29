#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream in("day3.txt");
    string s;
    int ans{0};
    while (in >> s)
    {
        int start, tens{0}, ones{0};
        for (size_t i{s.length() - 1}; i-- > 0;)
        {
            if (s[i] - '0' >= tens)
            {
                tens = s[i] - '0';
                start = i;
            }
        }
        for (int j{start + 1}; j < s.length(); ++j)
        {
            ones = s[j] - '0' > ones ? s[j] - '0' : ones;
        }
        ans += 10 * tens + ones;
    }
    cout << ans << endl;
    return 0;
}
