def printMt(x):
    if x == 1:
        print(x, end='')
        return

    printMt(x - 1)
    print(x, end='')
    printMt(x - 1)


printMt(int(input()))
