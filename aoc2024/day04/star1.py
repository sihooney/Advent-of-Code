cnt = 0
data = [list(line) for line in open('day4.txt', 'r').read().splitlines()]
N = len(data)
for i in range(N):
    for j in range(N):
        hor = ""
        vert = ""
        diagright = ""
        diagleft = ""
        for k in range(4):
            if j + k < N:
                hor += data[i][j + k]
            if i + k < N:
                vert += data[i + k][j]
                if j + k < N:
                    diagright += data[i + k][j + k]
                if j - k >= 0:
                    diagleft += data[i + k][j - k]
        if hor == 'XMAS' or hor == 'SAMX':
            cnt += 1
        if vert == 'XMAS' or vert == 'SAMX':
            cnt += 1
        if diagright == 'XMAS' or diagright == 'SAMX':
            cnt += 1
        if diagleft == 'XMAS' or diagleft == 'SAMX':
            cnt += 1
print(cnt)
