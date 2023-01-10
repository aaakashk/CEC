#include <iostream>
#include <array>

#define SIZE 10

void modified_bubble_sort(std::array<int, SIZE>& a) {
    for(int i = 0; i < a.size() - 1; ++i) {
	bool swapped = false;
	for(int j = 0; j < a.size() - 1 - i; ++j) {
	    if(a[j] > a[j + 1]) {
		swapped = true;
		int temp = a[j];
		a[j] = a[j + 1];
		a[j + 1] = temp;
	    }
	}
	if(!swapped) break;
    }
}

void print_array(std::array<int, SIZE>& a) {
    for(int i = 0; i < a.size(); ++i)
	std::cout << a[i] << " ";
    std::cout << "\n";
}

int main() {
    std::array<int, SIZE> a = {8, 5, 3, 2, 6, 10, 7, 91, 28, 31};
    modified_bubble_sort(a);
    print_array(a);
    return 0;
}
