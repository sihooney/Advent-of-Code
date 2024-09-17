from re import findall


f = open("day8.txt", 'r')
seq = f.readline().rstrip()
f.readline()
network = {}
while line := f.readline().rstrip():
    nodes = findall('[A-Z]{3,3}', line)
    network[nodes[0]] = nodes[1:]
f.close()
steps = 0
cur = 'AAA'
while cur != 'ZZZ':
    if seq[steps] == 'L':
        cur = network[cur][0]
    else:
        cur = network[cur][1]
    steps += 1
    if steps >= len(seq):
        seq += seq
print(steps)
