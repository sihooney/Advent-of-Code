#include <iostream>
using namespace std;

int main() {
    int t[4] = {40, 81, 77, 72};
    int d[4] = {219, 1012, 1365, 1089};
    int ways = 1;
    for (int race = 0; race < 4; race++) {
        int count = 0;
        for (int i = 0; i <= t[race]; i++) {
            if (i * (t[race] - i) > d[race]) {
                count++;
            }
        }
        ways *= count;
    }
    cout << ways << endl;

    return 0;
}
