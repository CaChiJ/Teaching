splited = input().split()   # slice string
A = int(splited[0])     # access through index and cast string value to int
B = int(splited[1])
# "A, B = map(int, input().split())" work same

print(A + B)
print(A - B)
print(A * B)
print(A // B)
print(A % B)
