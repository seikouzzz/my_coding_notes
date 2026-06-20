#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void bubbleSort(T* arr,int n) {
    for (int i = 0; i < n - 1; i++) {
        bool flag = true;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                flag = false;
            }
        }
        if (flag) break;
    }
}

template <typename T>
void bubbleSort(vector<T>& arr) {
    bubbleSort(arr.data(), (int)arr.size());
}

int main() {
    int arr[] = { 4, 1, 4, 2, 4 };
    bubbleSort(arr, 5);
    for (int i = 0; i < 5; i++) cout << arr[i] << ' ';
    cout << endl;
    vector<double> vec = { 2.0, 1.0, 8.5, 5.5, 5, 0.5 };
    bubbleSort(vec);
    int s = vec.size();
    for (int i = 0; i < s; i++) cout << vec[i] << ' ';
    cout << endl;
    return 0;
}