from re import findall
from math import prod


SIZE_X = 101
SIZE_Y = 103
TIME = 100
robots = map(lambda x: list(map(int, findall(r"-?\d+", x))), open("day14.txt").readlines())
ans = [0] * 4
for x, y, dx, dy in robots:
    x = (x + TIME * dx) % SIZE_X
    y = (y + TIME * dy) % SIZE_Y
    if x < SIZE_X // 2:
        if y < SIZE_Y // 2:
            ans[0] += 1
        elif y > SIZE_Y // 2:
            ans[1] += 1
    elif x > SIZE_X // 2:
        if y < SIZE_Y // 2:
            ans[2] += 1
        elif y > SIZE_Y // 2:
            ans[3] += 1
print(prod(ans))
