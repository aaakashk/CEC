#include <iostream>
#include <array>

#define SIZE 10

void bubble_sort(std::array<int, SIZE>& a) {
    for (int i = 0; i < a.size() - 1; ++i) {
        for (int j = 0; j < a.size() - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void print_array(std::array<int, SIZE> a) {
    for (int i = 0; i < a.size(); ++i)
        std::cout << a[i] << " ";
    std::cout << "\n";
}

int main() {
    std::array<int, SIZE> a{1, 8, 45, 2, 38, 19, 24, 21, 94, 56};
    bubble_sort(a);
    print_array(a);
    return 0;
}
