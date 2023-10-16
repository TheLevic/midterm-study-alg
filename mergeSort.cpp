#include <iostream>
#include <vector>

const int N = 5; // Global variable for the threshold value

void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void insertionSort(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        if (right - left + 1 <= N) {
            std::cout << "Using Insertion Sort: ";
            insertionSort(arr, left, right);
            printArray(arr);
        } else {
            std::cout << "Splitting: ";
            for (int i = left; i <= right; ++i) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;

            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);

            std::cout << "Merged: ";
            for (int i = left; i <= right; ++i) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        }
    }
}

int main() {
    std::vector<int> arr = {9001, 189, 90, 78, 100, 1001, 9002, 78900, 9888443};
    std::cout << "Original Array: ";
    printArray(arr);
    mergeSort(arr, 0, arr.size() - 1);
    std::cout << "Sorted Array: ";
    printArray(arr);
    return 0;
}
