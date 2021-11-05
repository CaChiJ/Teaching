N = int(input())
stars = ""

for i in range(N):
    stars += "*"
    print(("%%%ds" % (N)) % stars)
