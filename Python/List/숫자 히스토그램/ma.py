inputs = list(map(int, input().split()))[:-1]
height = max(inputs)
nowHeight = height

for h in range(height):
    for idx, value in enumerate(inputs):
        if nowHeight <= value:
            print(' *', end='')
        else:
            print('  ', end='')

    nowHeight -= 1
    print()

for value in inputs:
    print(' ', end='')
    print(value, end='')
