def check() -> bool:
    global a
    if a[0] < a[1]:
        return all(True if 1 <= a[i] - a[i - 1] <= 3 else False for i in range(1, len(a)))
    else:
        return all(True if 1 <= a[i - 1] - a[i] <= 3 else False for i in range(1, len(a)))


cnt = 0
for line in open("day2.txt", 'r').read().splitlines():
    a = [int(x) for x in line.split()]
    if check():
        cnt += 1
    else:
        i = 0
        while i < len(a):
            temp = a.pop(i)
            if check():
                cnt += 1
                break
            a.insert(i, temp)
            i += 1
            pass
print(cnt)
