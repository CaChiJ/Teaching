inputs = []

for r in range(9):
    inputs.append(list(map(int, input().split())))

for seg in range(9):
    segSum = 0
    row = (seg // 3) * 3
    col = (seg % 3) * 3

    # 0(0, 0) 1(0, 3) 2(0, 6)
    # 3(3, 0) 4(3, 3) 5(3, 6)
    # 6(6, 0) 7(6, 3) 8(6, 6)

    for r in range(3):
        for c in range(3):
            segSum += inputs[r + row][c + col]

    print(segSum)
