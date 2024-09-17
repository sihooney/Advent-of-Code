ans = 0
with open ('day2.txt', 'r') as data:
    for i in range(1, 101):
        game = data.readline().rstrip()
        possible = True
        subsets = [[x.split() for x in y.split(', ')] for y in game[game.find(':') + 2: ].split('; ')]
        for s in subsets:
            if possible:
                for color in s:
                    if (color[1] == 'red' and int(color[0]) > 12) or (color[1] == 'green' and int(color[0]) > 13) or (color[1] == 'blue' and int(color[0]) > 14):
                        possible = False
                        break
        if possible:
            ans += i
print(ans)
