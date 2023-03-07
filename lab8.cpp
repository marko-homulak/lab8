#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

void find_minimum(vector<int>& arr) {
    auto min = min_element(arr.begin(), arr.end());
    auto min_index = find(arr.begin(), arr.end(), *min);
    cout << "\nThe minimum is element " << *min << " under the number: " << min_index - arr.begin() + 1 << endl;
}

void find_sum_between_negatives(vector<int>& arr) {
    int first_neg_index = 0, second_neg_index = 0;
    double sum_between_negatives = 0.0;

    auto first_neg_iter = find_if(begin(arr), end(arr), [](int num) { return num < 0; });
    if (first_neg_iter != end(arr)) {
        first_neg_index = distance(begin(arr), first_neg_iter);
    }

    auto second_neg_iter = find_if(next(first_neg_iter), end(arr), [](int num) { return num < 0; });
    if (second_neg_iter != end(arr)) {
        second_neg_index = distance(begin(arr), second_neg_iter);
    }

    int neg_count = count_if(begin(arr), end(arr), [](int num) { return num < 0; });
    if (neg_count >= 2) {
        for (int i = first_neg_index + 1; i < second_neg_index; i++) {
            sum_between_negatives += arr[i];
        }
        cout << "Sum of elements between first and two negative elements: " << sum_between_negatives << endl << endl;
    }
    else {
        cout << "There are less than two negative elements in the array!" << endl << endl;
    }
}

void partition_and_print(vector<int>& arr) {
    stable_partition(begin(arr), end(arr), [](int num) { return num <= 1; });

    for (auto i = arr.begin(); i != arr.end(); ++i) {
        cout << *i << '\t';
    }
    cout << endl;
}

int main() {
    int rand_min = -99, rand_max = 99;
    int n;
    vector<int> arr;
    vector<int>::iterator min, min_index;

    cout << "Enter the size of the array >> ";
    cin >> n;

    cout << endl;

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        //arr.push_back(rand() % 201 - 100); 
        arr.push_back(rand_min + (rand() % (int)(rand_max - rand_min + 1)));
        cout << arr[i] << "\t";
    }
    arr.resize(n);
    cout << endl;

    find_minimum(arr);
    find_sum_between_negatives(arr);
    partition_and_print(arr);

    return 0;
}
