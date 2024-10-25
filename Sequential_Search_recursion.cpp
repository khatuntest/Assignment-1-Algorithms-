#include <iostream>
using namespace std;

const int SIZE = 100;

int sequential_search(int arr[], int size, int iter, int target) {
    if (iter == size) {
        return -1;
    }
    if (arr[iter] == target) {
        return iter;
    }
    return sequential_search(arr, size, iter + 1, target);
}

int main() {
    int size, target;
    cin >> size >> target;

    int arr[SIZE];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int res = sequential_search(arr, size, 0, target);

    if (res == -1) {
        cout << "Not found" << endl;
    } else {
        cout << "Found at index: " << res << endl;
    }

    return 0;
}


