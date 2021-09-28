def printSequence(bucket):
    if(len(bucket) - 1 == M):
        print(' '.join(map(str, bucket[1:])))
        return

    for i in range(bucket[-1] + 1, N + 1):
        bucket.append(i)
        printSequence(bucket)
        bucket.pop()


N, M = map(int, input().split())
printSequence([0])
