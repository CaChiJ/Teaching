# python list의 method 사용 금지(미리 원하는 크기로 초기화 한 후 인덱스로 접근해야 함)
# len 함수 사용 금지
# deque 사용 금지

import sys

input = sys.stdin.readline
N = int(input())
stack = [0 for i in range(N)]
size = 0

for i in range(N):
    command = input().strip()

    if command.startswith('push'):
        stack[size] = int(str(command[5:]))
        size += 1
    elif command == 'pop':
        if size == 0:
            print(-1)
        else:
            print(stack[size-1])
            size -= 1
    elif command == 'size':
        print(size)
    elif command == 'empty':
        print(1 if size == 0 else 0)
    elif command == 'top':
        print(stack[size-1] if size != 0 else -1)
