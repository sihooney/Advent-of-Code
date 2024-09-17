def hash(s: str) -> int:
    val = 0
    for c in s:
        val += ord(c)
        val *= 17
        val %= 256
    return val


with open("day15.txt") as f:
    seq = f.read().split(",")
boxes = [[] for _ in range(256)]
for step in seq:
    idx = step.find("-")
    if idx != -1:
        label = step[:idx]
        n = hash(label)
        for i in range(len(boxes[n])):
            if boxes[n][i][0] == label:
                del boxes[n][i]
                break
    else:
        idx = step.index("=")
        label = step[:idx]
        f_len = int(step[idx + 1:])
        found = False
        n = hash(label)
        for i in range(len(boxes[n])):
            if boxes[n][i][0] == label:
                boxes[n][i][1] = f_len
                found = True
                break
        if not found:
            boxes[n].append([label, f_len])
ans = 0
for i in range(256):
    for j in range(len(boxes[i])):
        ans += (i + 1) * (j + 1) * boxes[i][j][1]
print(ans)
