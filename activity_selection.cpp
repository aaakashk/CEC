#include <iostream>
#include <vector>

struct activity {
    int start, finish;
};

bool compare_activity(struct activity a1, struct activity a2) {
    return a1.finish < a2.finish;
}

int main() {
    int n;
    std::cin >> n;
    struct activity activity[n];
    for (int i = 0; i < n; i++) std::cin >> activity[i].start;
    for (int i = 0; i < n; i++) std::cin >> activity[i].finish;
    std::sort(activity, activity + n, compare_activity);
    int j = 0, count = 1;
    std::vector<int> vector;
    // std::cout << activity[j].start << " " << activity[j].finish << "\n";
    for (int i = 1; i < n; i++) {
        if (activity[i].start >= activity[j].finish) {
            count++;
            // std::cout << activity[i].start << " " << activity[i].finish << "\n";
            vector.push_back(i + 1);
            j = i;
        }
    }
    std::cout << "Total number of activities selected: " << count << "\n";
    std::cout << "Activities selected are: 1, ";
    for (int i = 0; i < vector.size(); i++) {
        std::cout << vector[i];
        i == vector.size() - 1 ? std::cout << "." : std::cout << ", ";
    }
    return 0;
}