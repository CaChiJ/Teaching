def pow(x, y):
    if y == 1:
        return x

    return x * pow(x, y - 1)


x, y = map(int, input().split())
print(pow(x, y))
