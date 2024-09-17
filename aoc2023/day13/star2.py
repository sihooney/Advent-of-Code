def find_lines(arr: list[list[chr]], vert: bool):
    lines = set()
    for col in range(1, len(arr[0])):
        symmetry = True
        for row in range(len(arr)):
            size = min(col, len(arr[0]) - col)
            if arr[row][col-size:col] != list(reversed(arr[row][col:col+size])):
                symmetry = False
                break
        if symmetry:
            if vert:
                lines.add(('v', col))
            else:
                lines.add(('h', col))
    return lines


def swap_row_col(arr: list[list[chr]]):
    swapped = [[0 for i in range(len(arr))] for j in range(len(arr[0]))]
    for i in range(len(arr)):
        for j in range(len(arr[0])):
            swapped[j][i] = arr[i][j]
    return swapped


def solve(arr: list[list[chr]]):
    return find_lines(arr, True).union(find_lines(swap_row_col(arr), False))


def smudge(arr: list[list[chr]]):
    prev = solve(arr)
    for i in range(len(arr)):
        for j in range(len(arr[0])):
            arr[i][j] = '.' if arr[i][j] == '#' else '#'
            new = solve(arr)
            if len(new) == 0 or new == prev:
                arr[i][j] = '.' if arr[i][j] == '#' else '#'
                continue
            return list(new - prev)[0]


with open("day13.txt", 'r') as f:
    data = [[list(x) for x in y.split()] for y in f.read().split("\n\n")]
ans = 0
for pattern in data:
    reflect = smudge(pattern)
    ans += reflect[1] if reflect[0] == 'v' else 100 * reflect[1]
print(ans)
