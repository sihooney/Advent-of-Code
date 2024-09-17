ans = 0
with open("day4.txt", 'r') as infile:
    while line := infile.readline().rstrip():
        count = 0
        winning = [int(i) for i in line[line.index(':') + 2: line.index('|') - 1].split()]
        nums = {int(j) for j in line[line.index('|') + 2:].split()}
        for x in winning:
            if x in nums:
                count += 1
        if count != 0:
            ans += 2 ** (count - 1)
print(ans)
