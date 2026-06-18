#include <iostream>
#include <vector>

using namespace std;

// 快速排序

template <typename T>
void quickSort(T* arr, int n) {
    if (n <= 1) return;
    T pivot = arr[n/2];
    int left = 0, right = n - 1;
    while (left <= right) {
        while (arr[left] < pivot) left++;
        while (pivot < arr[right]) right--;
        if (left <= right) {
            swap(arr[left], arr[right]);
            left++, right--;
        }
    }
    quickSort(arr, right + 1);
    quickSort(arr + left, n - left);
}

template <typename T>
void quickSort(vector<T>& arr) {
    quickSort(arr.data(), (int)arr.size());
}

int main() {
    int arr[] = { 4, 1, 4, 2, 4 };
    quickSort(arr, 5);
    for (int i = 0; i < 5; i++) cout << arr[i] << ' ';
    cout << endl;
    vector<double> vec = { 2.0, 1.0, 8.5, 5.5, 5, 0.5 };
    quickSort(vec);
    int s = vec.size();
    for (int i = 0; i < s; i++) cout << vec[i] << ' ';
    cout << endl;
    return 0;
}