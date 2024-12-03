from re import fullmatch


data = open('day3.txt', 'r').read()
on = True
res = 0
for i in range(len(data)):
    try:
        if data[i:i+4] == 'do()':
            on = True
        elif data[i:i+7] == 'don\'t()':
            on = False
    except IndexError:
        pass
    if on:
        try:
            s = data[i:data.index(')', i)+1]
            if fullmatch(r'mul\(\d+,\d+\)', s):
                comma = s.index(',')
                res += int(s[4:comma]) * int(s[comma+1:-1])
        except ValueError:
            pass
print(res)
