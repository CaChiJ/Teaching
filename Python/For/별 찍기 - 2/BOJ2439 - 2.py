N = int(input())
stars = ""

for i in range(N):
    stars += "*"
    print("%{0}s".format(N) % stars)
