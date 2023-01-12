#include <array>
#include <iostream>

#define SIZE 10

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(std::array<int, SIZE>& arr, const int start, const int end) {
    int pivot = arr[end];
    int i = start - 1;
    for (int j = start; j < end; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return i + 1;
}

void quick_sort(std::array<int, SIZE>& arr, const int start, const int end) {
    if (start >= end) return;
    int pi = partition(arr, start, end);
    quick_sort(arr, start, pi - 1);
    quick_sort(arr, pi + 1, end);
}

void print_array(std::array<int, SIZE>& arr) {
    for (int i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

int main() {
    std::array<int, SIZE> arr = {4, 19, 91, 392, 1, 25, 81, 9, 46, 21};
    quick_sort(arr, 0, SIZE - 1);
    print_array(arr);
    return 0;
}