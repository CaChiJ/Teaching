T = int(input())

for i in range(T):
    splited = input().split()
    A = int(splited[0])
    B = int(splited[1])
    # "A, B = map(int, input().split())" work same

    print("Case #{0}: {1} + {2} = {3}".format(i + 1, A, B, A + B))
