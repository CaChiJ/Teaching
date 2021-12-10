input()
inputs = input().split()
appeared = []

for idx, value in enumerate(inputs):
    isAppeared = False

    for i in appeared:
        if value == i:
            isAppeared = True
            break

    if not isAppeared:
        appeared.append(value)

print(len(appeared))
