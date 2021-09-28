def putDisk(origin, dest, count):
    if count == 1:
        print("%d -> %d" % (origin, dest))
        return

    putDisk(origin, 6-origin-dest, count-1)
    putDisk(origin, dest, 1)
    putDisk(6-origin-dest, dest, count-1)


putDisk(1, 3, int(input()))
