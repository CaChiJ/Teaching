input()
inputs = map(int, input().split())

minIdx = []
minValue = 1001

for idx, value in enumerate(inputs):
    if value < minValue:
        minIdx = [idx]
        minValue = value
    elif value == minValue:
        minIdx.append(idx)

for idx in minIdx:
    print(idx + 1, end=' ')
