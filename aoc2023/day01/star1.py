import re


ans = 0
for line in open('day1.txt', 'r').read().splitlines():
    line = re.sub('\D', '', line)
    ans += int(line[0]) * 10 + int(line[-1])
print(ans)
