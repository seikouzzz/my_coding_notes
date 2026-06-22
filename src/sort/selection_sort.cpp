#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void selectionSort(T* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n - 1; j++) {
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        if (minIdx != i) swap(arr[i], arr[minIdx]);
    }
}

template <typename T>
void selectionSort(vector<T>& vec) {
    selectionSort(vec.data(), vec.size());
}

int main() {
    int arr[] = { 4, 1, 4, 2, 4 };
    selectionSort(arr, 5);
    for (int i = 0; i < 5; i++) cout << arr[i] << ' ';
    cout << endl;
    vector<double> vec = { 2.0, 1.0, 8.5, 5.5, 5, 0.5 };
    selectionSort(vec);
    int s = vec.size();
    for (int i = 0; i < s; i++) cout << vec[i] << ' ';
    cout << endl;
    return 0;
}