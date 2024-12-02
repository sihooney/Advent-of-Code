a = []
b = []
for line in open('day1.txt', 'r').read().splitlines():
    x, y = list(map(int, line.split()))
    a.append(x)
    b.append(y)
a.sort()
b.sort()
print(sum(abs(i - j) for i, j in zip(a, b)))
