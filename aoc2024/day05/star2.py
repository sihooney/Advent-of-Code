from functools import cmp_to_key
from collections import defaultdict


def compare(x: int, y: int) -> int:
    global rules
    if y in rules[x]:
        return -1
    return 1


data = open('day5.txt', 'r').read().splitlines()
rules = defaultdict(set)
ans = 0
for line in data:
    if len(line) == 5:
        before, after = list(map(int, line.split('|')))
        rules[before].add(after)
    elif len(line) > 0:
        a = list(map(int, line.split(',')))
        pos = [-1 for _ in range(101)]
        for i in range(len(a)):
            pos[a[i]] = i
        wrong = False
        for key in a:
            for z in rules[key]:
                if pos[z] != -1 and pos[key] > pos[z]:
                    a.sort(key=cmp_to_key(compare))
                    wrong = True
                    break
        if wrong:
            ans += a[len(a) // 2]
print(ans)
