#include <iostream>

int fact(int n) {
    if(n == 0) return 1;
    return n * fact(n - 1);
}

int main() {
    int n = 5;
    std::cout << "Factorial of " << n << " = " << fact(n) << "\n";
    return 0;
}
