def solve(arr: list[list[chr]]):
    for col in range(1, len(arr[0])):
        symmetry = True
        for row in range(len(arr)):
            size = min(col, len(arr[0]) - col)
            if arr[row][col-size:col] != list(reversed(arr[row][col:col+size])):
                symmetry = False
                break
        if symmetry:
            return col
    return -1


def swap_row_col(arr: list[list[chr]]):
    res = [[0 for i in range(len(arr))] for j in range(len(arr[0]))]
    for i in range(len(arr)):
        for j in range(len(arr[0])):
            res[j][i] = arr[i][j]
    return res


with open("day13.txt", 'r') as f:
    data = [[list(x) for x in y.split()] for y in f.read().split("\n\n")]
ans = 0
for pattern in data:
    vert = solve(pattern)
    ans += vert if vert != -1 else solve(swap_row_col(pattern)) * 100
print(ans)
