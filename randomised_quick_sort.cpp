#include <array>
#include <cstdlib>
#include <ctime>
#include <iostream>

#define SIZE 10

void shuffle(std::array<int, SIZE>& arr) {
    srand(time(NULL));
    for (int i = SIZE - 1; i > 0; --i) {
        int random_index = rand() % (i + 1);
        std::swap(arr[i], arr[random_index]);
    }
}

int partition(std::array<int, SIZE>& arr, const int start, const int end) {
    int pivot = arr[end];
    int i = start - 1;
    for (int j = start; j < end; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[end]);
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
    shuffle(arr);
    quick_sort(arr, 0, SIZE - 1);
    print_array(arr);
    return 0;
}