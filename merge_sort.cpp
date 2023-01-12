#include <iostream>

#define SIZE 10

void merge(int arr[], const int low, const int mid, const int high) {
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int leftArray[n1];
    int rightArray[n2];

    for (i = 0; i < n1; i++)
        leftArray[i] = arr[low + i];

    for (j = 0; j < n2; j++)
        rightArray[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = low;

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k++] = leftArray[i++];
        } else
            arr[k++] = rightArray[j++];
    }

    while (i < n1) {
        arr[k++] = leftArray[i++];
    }

    while (j < n2) {
        arr[k++] = rightArray[j++];
    }
}

void merge_sort(int arr[], const int low, const int high) {
    if (low >= high) return;
    int mid = low + (high - low) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void print_array(int arr[]) {
    for (int i = 0; i < SIZE; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}
int main() {
    int arr[SIZE] = {4, 19, 91, 392, 1, 25, 81, 9, 46, 21};
    merge_sort(arr, 0, SIZE - 1);
    print_array(arr);
    return 0;
}