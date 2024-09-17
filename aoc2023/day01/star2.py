import re


ans = 0
for line in open('day1.txt', 'r').read().splitlines():
    line = line.replace('one', 'o1e')
    line = line.replace('two', 't2o')
    line = line.replace('three', 't3e')
    line = line.replace('four', '4')
    line = line.replace('five', '5e')
    line = line.replace('six', '6')
    line = line.replace('seven', '7n')
    line = line.replace('eight', 'e8t')
    line = line.replace('nine', 'n9e')
    line = re.sub('\D', '', line)
    ans += int(line[0]) * 10 + int(line[-1])
print(ans)
