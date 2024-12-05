data = open('day5.txt', 'r').read().splitlines()
rules = []
ans = 0
for line in data:
    if len(line) == 5:
        rules.append(list(map(int, line.split('|'))))
    elif len(line) > 0:
        a = list(map(int, line.split(',')))
        pos = [-1 for _ in range(101)]
        for i in range(len(a)):
            pos[a[i]] = i
        ans += a[len(a) // 2]
        for [x, y] in rules:
            if pos[x] != -1 and pos[y] != -1 and pos[x] > pos[y]:
                ans -= a[len(a) // 2]
                break
print(ans)
