from itertools import product


all_combs = [list(product([0, 1, 2], repeat=n)) for n in range(12)]
data = open('day7.txt').readlines()
ans = 0
for line in data:
    val = int(line[:line.index(':')])
    a = list(map(int, line[line.index(':') + 1:].split()))
    res = a[0]
    for comb in all_combs[len(a) - 1]:
        for i in range(len(comb)):
            if comb[i] == 0:
                res += a[i + 1]
            elif comb[i] == 1:
                res *= a[i + 1]
            else:
                res = int(str(res) + str(a[i + 1]))
        if res == val:
            ans += val
            break
        res = a[0]
print(ans)
