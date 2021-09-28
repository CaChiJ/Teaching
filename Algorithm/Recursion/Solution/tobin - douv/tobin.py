def printBin(n):
    if n != 1:
        printBin(n // 2)

    print(n % 2, end='')


printBin(int(input()))
