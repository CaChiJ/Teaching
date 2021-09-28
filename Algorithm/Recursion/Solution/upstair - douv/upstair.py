def getNumOfCase(n):
    if n == 0 or n == 1:
        return 1

    return getNumOfCase(n-1) + getNumOfCase(n-2)


print(getNumOfCase(int(input())))
