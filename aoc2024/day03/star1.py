from re import findall


matches = findall(r'mul\(\d+,\d+\)', open('day3.txt', 'r').read())
res = 0
for s in matches:
    i = s.index(',')
    res += int(s[4:i]) * int(s[i+1:-1])
print(res)
