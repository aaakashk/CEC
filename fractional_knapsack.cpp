#include <iostream>
#include <vector>

struct item {
    int weight, value, id;  // id is used to store item's number, mainly for printing purposes
};

bool compare_items(struct item i1, struct item i2) {
    double a = (double)i1.value / (double)i1.weight;
    double b = (double)i2.value / (double)i2.weight;
    return a > b;
}

double fractional_knapsack(struct item arr[], int weight, int n, std::vector<std::pair<int, int> >& vector) {
    int i = 0;
    double result = 0.0;
    while (weight) {
        if (arr[i].weight <= weight) {
            weight -= arr[i].weight;
            result += arr[i].value;
            vector.push_back(std::make_pair(arr[i].id, arr[i].weight));  // to print item's id and weight
            i++;
        } else {
            result += arr[i].value * ((double)weight / (double)arr[i].weight);
            vector.push_back(std::make_pair(arr[i].id, weight));  // again, to print item's id and weight
            break;
        }
    }
    return result;
}

int main() {
    int n;
    std::cin >> n;
    struct item arr[n];
    for (int i = 0; i < n; i++) std::cin >> arr[i].weight;
    for (int i = 0; i < n; i++) std::cin >> arr[i].value;
    for (int i = 0; i < n; i++) arr[i].id = i + 1;
    int weight;
    std::cin >> weight;
    std::sort(arr, arr + n, compare_items);
    std::vector<std::pair<int, int> > vector;
    std::cout << "Maximum Weight: " << fractional_knapsack(arr, weight, n, vector);
    std::cout << "\nItem : Weight\n";
    for (std::pair<int, int> p : vector) {
        std::cout << p.first << "    : " << p.second << "\n";
    }
    return 0;
}