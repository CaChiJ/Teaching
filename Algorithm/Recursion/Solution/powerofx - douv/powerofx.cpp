#include <iostream>

int pow(int x, int y) {
    if(y == 1) {
        return x;
    }

    return x * pow(x, y-1);
}

int main(void) {
    int x, y;
    std::cin >> x >> y;
    std::cout << pow(x, y) << std::endl;
    return 0;
}