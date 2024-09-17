from re import findall
from math import lcm


f = open("day8.txt", 'r')
seq = 100 * f.readline().rstrip()
f.readline()
network = {}
pos = []
while line := f.readline().rstrip():
    nodes = findall('[1-9A-Z]{3,3}', line)
    network[nodes[0]] = nodes[1:]
    if nodes[0][-1] == 'A':
        pos.append(nodes[0])
f.close()
steps = []
path_idx = 0
finish = len(pos)
while len(steps) != finish:
    i = 0
    while i < len(pos):
        if seq[path_idx] == 'L':
            pos[i] = network[pos[i]][0]
        else:
            pos[i] = network[pos[i]][1]
        if pos[i][-1] == 'Z':
            steps.append(path_idx + 1)
            del pos[i]
        else:
            i += 1
    path_idx += 1
print(lcm(*steps))
