a = set()
b = {}
for line in open('day1.txt', 'r').read().splitlines():
    x, y = list(map(int, line.split()))
    a.add(x)
    b[y] = b[y] + 1 if y in b else 1
print(sum(b.get(i, 0) * i for i in a))
