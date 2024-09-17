from collections import Counter


total = 0
hands = {}
royals = {'A': 14, 'K': 13, "Q": 12, 'J': 11, 'T' : 10};
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
    counts = [n[1] for n in Counter(h).most_common()]
    if counts == [1, 1, 1, 1, 1]:
        order[0].append(h)
    elif counts == [2, 1, 1, 1]:
        order[1].append(h)
    elif counts == [2, 2, 1]:
        order[2].append(h)
    elif counts == [3, 1, 1]:
        order[3].append(h)
    elif counts == [3, 2]:
        order[4].append(h)
    elif counts == [4, 1]:
        order[5].append(h)
    elif counts == [5]:
        order[6].append(h)
for group in order:
    group.sort()
rank = 1
for i in range(7):
    for c in order[i]:
        total += rank * hands[c]
        rank += 1
print(total)
