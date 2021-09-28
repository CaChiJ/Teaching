def gcd(a, b):
    if a < b:
        a, b = b, a

    mod = a % b

    if mod == 0:
        return b

    return gcd(b, mod)


x, y = map(int, input().split())
g = gcd(x, y)
print("%d %d" % (g, x * y / g))
