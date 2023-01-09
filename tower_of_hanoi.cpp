#include <iostream>

void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if(n == 0) return;
    tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod);
    std::cout << "move disk " << n << " from rod " << from_rod << " to rod " << to_rod << "\n";
    tower_of_hanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n = 4;
    tower_of_hanoi(n, 'a', 'c', 'b');
    return 0;
}
