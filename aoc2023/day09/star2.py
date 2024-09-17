data = [[int(x) for x in s.split()] for s in open('day9.txt')]
ans = 0
for a in data:
    first = [a[0]]
    while any(a) is True:
        for i in range(len(a) - 1):
            a[i] = a[i + 1] - a[i]
        a.pop()
        first.append(a[0])
    for i in range(len(first) - 2, -1, -1):
        first[i] -= first[i + 1]
    ans += first[0]
print(ans)
