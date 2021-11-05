N = int(input())
stars = ""

for i in range(N):
    stars += "*"
    print("{{0:>{0}}}".format(N).format(stars))
