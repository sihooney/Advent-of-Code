#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include <vector>

using namespace std;

int main() {
    char grid[150][150];
    memset(grid, '.', sizeof(grid));
    pair<int, int> search[8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    ifstream infile("day3.txt");
    for (int i = 1; i <= 140; i++) {
        for (int j = 1; j <= 140; j++) {
            infile.get(grid[i][j]);
        }
        infile.get(grid[0][0]);
    }
    infile.close();
    int ans = 0;
    for (int i = 1; i <= 140; i++) {
        for (int j = 1; j <= 140; j++) {
            if (grid[i][j] == '*') {
                vector<int> parts;
                for (auto dir: search) {
                    int y = i + dir.first, x = j + dir.second;
                    if (isdigit(grid[y][x])) {
                        while (isdigit(grid[y][x])) {
                            x--;
                        }
                        x++;
                        string num;
                        while (isdigit(grid[y][x])) {
                            num += grid[y][x];
                            grid[y][x] = '.';
                            x++;
                        }
                        parts.push_back(stoi(num));
                    }
                }
                if (parts.size() == 2) {
                    ans += parts[0] * parts[1];
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
