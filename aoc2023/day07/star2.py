from collections import Counter


total = 0
hands = {}
royals = {'A': 14, 'K': 13, "Q": 12, 'J': 1, 'T' : 10};
with open("day7.txt", 'r') as f:
    while line := f.readline().rstrip().split():
        cards = []
        for i in range(5):
            if line[0][i] in royals:
                cards.append(royals[line[0][i]])
            else:
                cards.append(int(line[0][i]))
        hands[tuple(cards)] = int(line[1])
order = [[] for i in range(7)]
for h in hands.keys():
    counts = Counter(h)
    old = counts.most_common()
    if 1 in counts:
        if counts[1] != 5:
            if old[0][0] != 1:
                counts[old[0][0]] += counts[1]
            elif counts[1] != 5:
                counts[old[1][0]] += counts[1]
            del counts[1]
    modified = counts.most_common()
    freq = [n[1] for n in modified]
    if freq == [1, 1, 1, 1, 1]:
        order[0].append(h)
    elif freq == [2, 1, 1, 1]:
        order[1].append(h)
    elif freq == [2, 2, 1]:
        order[2].append(h)
    elif freq == [3, 1, 1]:
        order[3].append(h)
    elif freq == [3, 2]:
        order[4].append(h)
    elif freq == [4, 1]:
        order[5].append(h)
    elif freq == [5]:
        order[6].append(h)
for group in order:
    group.sort()
rank = 1
for i in range(7):
    for c in order[i]:
        total += rank * hands[c]
        rank += 1
print(total)
