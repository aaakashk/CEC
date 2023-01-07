#include <iostream>
#include <array>

#define SIZE 10

int binary_search(std::array<int, SIZE> array, int low, int high, int value) {
   while(low <= high) {
	int mid = low + (high - low) / 2;
	if(array[mid] == value) return mid;
	else if(array[mid] > value) high = mid - 1 ;
	else low = mid + 1;
    }
    return -1;
} 

int main() {
    std::array<int, SIZE> array = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int value = 4;
    int index = binary_search(array, 0, array.size() - 1, value);
    if(index >= 0) std::cout << "Element present at index = " << index << ".\n";
    else std::cout << "Element not found.\n";
    return 0;
}
    
