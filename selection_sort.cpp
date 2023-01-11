#include <array>
#include <iostream>

#define SIZE 10

void selection_sort(std::array<int, SIZE>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        int min = arr[i];
        int min_index = i;
        for (int j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < min) {
                min = arr[j];
                min_index = j;
            }
        }
        if (min != arr[i]) {
            arr[min_index] = arr[i];
            arr[i] = min;
        }
    }
}

void print_array(std::array<int, SIZE>& arr) {
    for (int i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

int main() {
    std::array<int, SIZE> array = {4, 19, 91, 392, 1, 25, 81, 9, 46, 21};
    selection_sort(array);
    print_array(array);
    return 0;
}