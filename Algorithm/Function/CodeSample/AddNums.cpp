#include <iostream>

int AddNums(int a, int b) {
    return a + b;
}

int main(void) {
    int result1 = AddNums(1, 2);
    std::cout << result1 << std::endl;

    int result2 = AddNums(-3, 5);
    std::cout << result2 << std::endl;

    return 0;
}