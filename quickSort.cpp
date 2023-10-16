#include <iostream>
#include <vector>

int choosePivot(std::vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;

    // Choose the median of the first, middle, and last elements
    if (arr[low] > arr[mid])
        std::swap(arr[low], arr[mid]);
    if (arr[low] > arr[high])
        std::swap(arr[low], arr[high]);
    if (arr[mid] > arr[high])
        std::swap(arr[mid], arr[high]);

    // Move the median to the last position as the pivot
    std::swap(arr[mid], arr[high]);
    return high; // Pivot index is now 'high'
}

int partition(std::vector<int>& arr, int low, int high, int pivotIndex) {
    int pivot = arr[pivotIndex];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = choosePivot(arr, low, high);
        int pi = partition(arr, low, high, pivotIndex);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};

    std::cout << "Original Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    quickSort(arr, 0, arr.size() - 1);

    std::cout << "Sorted Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}