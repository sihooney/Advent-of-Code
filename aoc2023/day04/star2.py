freq = [1] * 219
with open("day4.txt", 'r') as infile:
    matches = []
    for i in range(219):
        s = infile.readline().rstrip()
        matches.append(len({int(i) for i in s[s.index(':') + 2: s.index('|') - 1].split()} & {int(j) for j in s[s.index('|') + 2:].split()}))
for i in range(219):
    for num in range(1, matches[i] + 1):
        if i + num < 219:
            freq[i + num] += freq[i]
print(sum(freq))
