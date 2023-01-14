#include <cstring>
#include <iostream>

#define SIZE 18

void print_array(int arr[]) {
    for (int i = 0; i < SIZE; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

void count_sort(int arr[]) {
    int max_element = *std::max_element(arr, arr + SIZE);
    int output[SIZE];
    int count[max_element + 1];
    memset(count, 0, sizeof(count));
    // count of each element
    for (int i = 0; i < SIZE; ++i)
        ++count[arr[i]];
    // cumulative count
    for (int i = 1; i <= max_element; ++i)
        count[i] += count[i - 1];
    // ordering numbers in a new array
    for (int i = 0; i < SIZE; ++i)
        output[--count[arr[i]]] = arr[i];
    // copying back to original array
    for (int i = 0; i < SIZE; ++i)
        arr[i] = output[i];
}

int main() {
    int arr[SIZE] = {5, 2, 5, 5, 3, 1, 2, 5, 1, 5, 0, 5, 3, 1, 5, 2, 2, 2};
    count_sort(arr);
    print_array(arr);
    return 0;
}