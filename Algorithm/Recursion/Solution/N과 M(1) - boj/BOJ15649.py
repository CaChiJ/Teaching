def printSequnce(bucket, isUsed):
    if len(bucket) == M:
        print(' '.join(map(str, bucket)))

    for i in range(N):
        if isUsed[i + 1]:
            continue

        isUsed[i + 1] = True
        bucket.append(i + 1)
        printSequnce(bucket, isUsed)
        bucket.pop()
        isUsed[i + 1] = False


N, M = map(int, input().split())
printSequnce([], [False for i in range(N + 1)])
