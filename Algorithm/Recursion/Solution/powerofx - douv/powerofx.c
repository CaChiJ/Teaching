#include <stdio.h>

int myPow(int x, int y) {
    if (y == 1) {
        return x;
    }

    return x * myPow(x, y - 1);
}

int main(void) {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d", myPow(x, y));
    return 0;
}