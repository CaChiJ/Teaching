splited = input().split()
A = int(splited[0])
B = int(splited[1])
# "A, B = map(int, input().split())" work same

if A > B:
    print(">")
elif A < B:
    print("<")
else:
    print("==")
