#include <iostream>
#include <array>

#define SIZE 10

int linear_search(std::array<int, SIZE> array, int value) {
    for(int i = 0; i < array.size(); ++i)
	if(array[i] == value) return i;
    return -1;
}

int main() {
    std::array<int, SIZE> array = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int value = 9;
    int index = linear_search(array, value);
    if(index >= 0) std::cout << "Element present at index = " << index << "\n";
    else std::cout << "Element not found.\n";
    return 0;
}
