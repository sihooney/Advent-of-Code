data = [[int(x) for x in s.split()] for s in open('day9.txt')]
ans = 0
for a in data:
    ans += a[-1]
    while any(a) is True:
        for i in range(len(a) - 1):
            a[i] = a[i + 1] - a[i]
        a.pop()
        ans += a[-1]
print(ans)
