cnt = 0
data = [list(line) for line in open('day4.txt', 'r').read().splitlines()]
N = len(data)
for i in range(N):
    for j in range(N):
        try:
            hor = ""
            for k in range(4):
                hor += data[i][j + k]
            if hor == 'XMAS' or hor == 'SAMX':
                cnt += 1
        except IndexError:
            pass
        try:
            vert = ""
            for k in range(4):
                vert += data[i + k][j]
            if vert == 'XMAS' or vert == 'SAMX':
                cnt += 1
        except IndexError:
            pass
        try:
            diagright = ""
            for k in range(4):
                diagright += data[i + k][j + k]
            if diagright == 'XMAS' or diagright == 'SAMX':
                cnt += 1
        except IndexError:
            pass
        try:
            diagleft = ""
            for k in range(4):
                if j - k < 0:
                    raise IndexError
                diagleft += data[i + k][j - k]
            if diagleft == 'XMAS' or diagleft == 'SAMX':
                cnt += 1
        except IndexError:
            pass
print(cnt)
