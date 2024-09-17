def hash(s: str) -> int:
    val = 0
    for c in s:
        val += ord(c)
        val *= 17
        val %= 256
    return val


with open("day15.txt") as f:
    seq = f.read().split(",")
ans = 0
for step in seq:
    ans += hash(step)
print(ans)
