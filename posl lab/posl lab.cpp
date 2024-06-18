#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <Windows.h>

using namespace std;

class MergeSort {
public:
    void Sort(vector<int>& arr) {
        if (arr.size() <= 1) return;

        int mid = arr.size() / 2;
        vector<int> left(arr.begin(), arr.begin() + mid);
        vector<int> right(arr.begin() + mid, arr.end());

        Sort(left);
        Sort(right);

        Merge(arr, left, right);
    }

    void Merge(vector<int>& result, vector<int>& left, vector<int>& right) {
        int i = 0, j = 0, k = 0;

        while (i < left.size() && j < right.size()) {
            if (left[i] < right[j]) {
                result[k] = left[i];
                i++;
            }
            else {
                result[k] = right[j];
                j++;
            }
            k++;
        }

        while (i < left.size()) {
            result[k] = left[i];
            i++;
            k++;
        }

        while (j < right.size()) {
            result[k] = right[j];
            j++;
            k++;
        }
    }
};

int main() {
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    vector<int> arr(10);
    cout << "Введите 10 чисел для сортировки: ";
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    MergeSort mergeSort;

    auto sortFunc = [&]() {
        mergeSort.Sort(arr);
        };

    thread mergeSortThread(sortFunc);

    mergeSortThread.join();

    cout << "Результат: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}