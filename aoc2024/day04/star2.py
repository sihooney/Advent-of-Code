cnt = 0
data = [list(line) for line in open('day4.txt', 'r').read().splitlines()]
N = len(data)
for i in range(1, N - 1):
    for j in range(1, N - 1):
        if data[i][j] != 'A':
            continue
        x = data[i - 1][j - 1] + data[i + 1][j + 1]
        y = data[i - 1][j + 1] + data[i + 1][j - 1]
        if (x == 'MS' or x == 'SM') and (y == 'MS' or y == 'SM'):
            cnt += 1
print(cnt)
