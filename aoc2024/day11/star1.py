from functools import cache


@cache
def f(x: int, blinks: int) -> int:
    if blinks == 0:
        return 1
    if x == 0:
        return f(1, blinks - 1)
    else:
        s = str(x)
        if len(s) % 2 == 0:
            return f(int(s[0:len(s) // 2]), blinks - 1) + f(int(s[len(s) // 2:]), blinks - 1)
        else:
            return f(x * 2024, blinks - 1)


a = list(map(int, open("day11.txt").readline().split()))
ans = 0
for val in a:
    ans += f(val, 25)
print(ans)
