#include <iostream>
#include <string>

void SayHello(std::string str) {
    std::cout << "Hello, " <<  str << "!" << std::endl;
}

int main(void) {
    std::string name1 = "World";
    SayHello(name1);

    std::string name2 = "Choi";
    SayHello(name2);
    
    return 0;
}