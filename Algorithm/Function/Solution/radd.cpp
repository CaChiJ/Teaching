#include <iostream>

int reverse(int num) {
    int rNum = 0;    // reversed number

    while(num != 0) {
        rNum *= 10;
        rNum += num % 10;
        num /= 10;
    }

    return rNum;
}

int main(void) {
    int a, b;
    std::cin >> a >> b;
    
    int rSum = reverse(a) + reverse(b);    // sum of reversed numbers
    std::cout << reverse(rSum) << std::endl;
    return 0;
}