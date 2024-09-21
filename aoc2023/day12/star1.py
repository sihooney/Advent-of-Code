from re import sub, finditer


data = [l.split() for l in open("day12.txt", 'r')]
ans = 0
for line in data:
    pos = [m.start() for m in finditer(r'\?', line[0])]
    for x in range(2 ** len(pos)):
        s = list(line[0])
        bitmask = bin(x)[2:]
        bitmask = (len(pos) - len(bitmask)) * '0' + bitmask
        for i in range(len(bitmask)):
            s[pos[i]] = '#' if bitmask[i] == '1' else '.'
        s = sub(r'\.+', ',', sub(r'(#+)', lambda match: str(len(match.group(0))), ''.join(s))).strip(',')
        if s == line[1]:
            ans += 1
print(ans)
