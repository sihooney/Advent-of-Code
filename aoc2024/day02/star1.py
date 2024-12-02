cnt = 0
for line in open("day2.txt", 'r').read().splitlines():
    a = [int(x) for x in line.split()]
    if a[0] < a[1]:
        cnt += all(True if 1 <= a[i] - a[i - 1] <= 3 else False for i in range(1, len(a)))
    else:
        cnt += all(True if 1 <= a[i - 1] - a[i] <= 3 else False for i in range(1, len(a)))
print(cnt)
