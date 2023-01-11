#include <array>
#include <iostream>

#define SIZE 10

void insertion_sort(std::array<int, SIZE>& arr) {
    for (int i = 1; i < arr.size(); ++i) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void print_array(std::array<int, SIZE>& arr) {
    for (int i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

int main() {
    std::array<int, SIZE> arr = {4, 19, 91, 392, 1, 25, 81, 9, 46, 21};
    insertion_sort(arr);
    print_array(arr);
    return 0;
}