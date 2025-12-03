#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("day3.txt");
    string s;
    int ans{0};
    while (in >> s)
    {
        int start, tens{0}, ones{0};
        for (int i = s.length() - 2; i >= 0; --i)
        {
            if (s[i] - '0' >= tens)
            {
                tens = s[i] - '0';
                start = i;
            }
        }
        for (int j = start + 1; j < s.length(); ++j)
        {
            ones = s[j] - '0' > ones ? s[j] - '0' : ones;
        }
        ans += 10 * tens + ones;
    }
    cout << ans << endl;
    return 0;
}
