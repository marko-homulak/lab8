#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

auto find_minimum(vector<int>& arr) {
    auto min = min_element(arr.begin(), arr.end());
    auto min_index = find(arr.begin(), arr.end(), *min);
    cout << "The minimum is element (" << *min << ") under the number (" << min_index - arr.begin() + 1 << ")" << endl;

    return min_index;
}

auto find_maximum(vector<int>& arr) {
    auto max = max_element(arr.begin(), arr.end());
    auto max_index = find(arr.begin(), arr.end(), *max);
    cout << "The maximum is element (" << *max << ") under the number (" << max_index - arr.begin() + 1 << ")" << endl;

    return max_index;
}

void find_sum_between_negatives(vector<int>& arr) {
    int first_neg_index = 0, second_neg_index = 0;
    double sum_between_negatives = 0.0;

    int neg_count = count_if(begin(arr), end(arr), [](int num) { return num < 0; });
    if (neg_count >= 2) {
        auto first_neg_iter = find_if(begin(arr), end(arr), [](int num) { return num < 0; });
        if (first_neg_iter != end(arr)) {
            first_neg_index = distance(begin(arr), first_neg_iter);
        }
        auto second_neg_iter = find_if(next(first_neg_iter), end(arr), [](int num) { return num < 0; });
        if (second_neg_iter != end(arr)) {
            second_neg_index = distance(begin(arr), second_neg_iter);
        }
        for (int i = first_neg_index + 1; i < second_neg_index; i++) {
            sum_between_negatives += arr[i];
        }
        cout << "Sum of elements between first and two negative elements: " << sum_between_negatives << endl;
    }
    else {
        cout << "There are less than two negative elements in the array!" << endl;
    }
}

void find_sum_between_min_and_max(vector<int>& arr, vector<int>::iterator min_index, vector<int>::iterator max_index) {
    double sum_between_min_max = 0.0;

    if (min_index > max_index) {
        swap(min_index, max_index);
    }

    for (auto it = next(min_index); it != max_index; it++) {
        sum_between_min_max += *it;
    }
    cout << "Sum of elements between minimum and maximum: " << sum_between_min_max << endl;
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
    vector<int>::iterator min_i, max_i;

    try {
        cout << "Enter the size of the array >> ";
        cin >> n;
        if (n <= 0) {
            throw (n);
        }
        else {
            cout << endl;

            srand(time(NULL));
            for (int i = 0; i < n; i++) {
                //arr.push_back(rand() % 201 - 100); 
                arr.push_back(rand_min + (rand() % (int)(rand_max - rand_min + 1)));
                cout << arr[i] << "\t";
            }
            arr.resize(n);

            cout << endl << endl;

            min_i = find_minimum(arr);
            max_i = find_maximum(arr);
            find_sum_between_negatives(arr);
            find_sum_between_min_and_max(arr, min_i, max_i);

            cout << endl;

            partition_and_print(arr);
        }
    }
    catch (int num) {
        cout << "Error! The size of the array must be positive value!" << endl;
    }
    
    return 0;
}
