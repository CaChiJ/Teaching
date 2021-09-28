def printMt(x, n):
    if x == n:
        print(x, end='')
        return

    print(x, end='')
    printMt(x + 1, n)
    print(x, end='')


printMt(1, int(input()))
