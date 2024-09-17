#include <iostream>
using namespace std;

int main() {
    long long x1, x2, t = 40817772, d = 219101213651089;
    for (int i = 0; i <= t; i++) {
        if ((t - i) * i > d) {
            x1 = i;
            break;
        }
    }
    for (int j = t; j >= 0; j--) {
        if ((t - j) * j > d) {
            x2 = j;
            break;
        }
    }
    cout << x2 - x1 + 1 << endl;

    return 0;
}
