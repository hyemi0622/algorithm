#include <iostream>

// 두 정수의 합을 반환하는 함수
int add(int a, int b) {
    return a + b;
}

int main() {
    int x, y;
    std::cout << "Enter two numbers: ";
    std::cin >> x >> y;

    std::cout << "Sum: " << add(x, y) << std::endl;
    return 0;
}

