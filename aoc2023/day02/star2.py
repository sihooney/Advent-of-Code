ans = 0
with open ('day2.txt', 'r') as data:
    for i in range(1, 101):
        game = data.readline().rstrip()
        subsets = [{x[x.find(' ') + 1:]: int(x[:x.find(' ')]) for x in y.split(', ')} for y in game[game.find(':') + 2:].split('; ')]
        least = {'red' : 0, 'green' : 0, 'blue' : 0}
        for s in subsets:
            for color, n in s.items():
                least[color] = max(least[color], n)
        ans += least['red'] * least['green'] * least['blue']
print(ans)
