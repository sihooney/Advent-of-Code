from numpy import linalg
from re import findall


data = list(map(lambda s: list(map(int, findall(r'\d+', s))), open("day13.txt").read().split("\n\n")))
ans = 0
for arr in data:
    sol = linalg.solve([[arr[0], arr[2]], [arr[1], arr[3]]], [arr[4] + 1e13, arr[5] + 1e13])
    if abs(sol[0] - round(sol[0])) < 1e-4 and abs(sol[1] - round(sol[1])) < 1e-4:
        ans += 3 * sol[0] + sol[1]
print(int(ans))
