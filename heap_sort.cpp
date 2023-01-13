#include <iostream>

#define SIZE 10

void heapify(int* array, int n, int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    if (l < n && array[l] > array[largest])
        largest = l;
    if (r < n && array[r] > array[largest])
        largest = r;
    if (largest != i) {
        std::swap(array[i], array[largest]);
        heapify(array, n, largest);
    }
}

void build_heap(int array[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(array, n, i);
    }
}

void heap_sort(int array[], int n) {
    build_heap(array, n);
    for (int i = n - 1; i > 0; i--) {
        std::swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}

void print_array(int array[], int n) {
    for (int i = 0; i < n; i++)
        std::cout << array[i] << " ";
    std::cout << "\n";
}

int main() {
    int array[SIZE] = {5, 3, 17, 10, 84, 19, 6, 22, 9, 10};
    heap_sort(array, SIZE);
    print_array(array, SIZE);

    return 0;
}