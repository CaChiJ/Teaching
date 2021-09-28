def printSequence(bucket):
    if len(bucket) == M:
        print(' '.join(map(str, bucket)))
        return

    for i in range(N):
        bucket.append(i + 1)
        printSequence(bucket)
        bucket.pop()


N, M = map(int, input().split())
printSequence([])
