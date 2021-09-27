#include <iostream>

int fibo(int n) {
    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    return fibo(n - 1) + fibo(n - 2);
}

int main(void) {
    int N;
    std::cin >> N;
    std::cout << fibo(N) << std::endl;
    return 0;
}