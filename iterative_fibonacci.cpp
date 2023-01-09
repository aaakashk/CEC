#include <iostream>

int fib(int n) {
    int a = 0, b = 1, c = 1;
    for(int i = 1; i < n; ++i) {
	c = a + b;
	a = b;
	b = c;
    }
    return b;
}

int main() {
    int n = 10;
    std::cout << "fib(" << n << ") = " << fib(n) << "\n";
    return 0;
}
