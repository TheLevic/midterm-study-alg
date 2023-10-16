#include <iostream>
#include <vector>

/* Bubble Sort (Worse than Insertion Sort)
 * Worst Case Run Time : O(n^2) If the whole array is unsorted or reverse order
 * Average Case Run Time : O(n^2)
 * Best Case Run Time : O(n) Already sorted
 * Space Complexity: O(1), uses a constant amount of memory space regardless of input size
*/
template <typename Type>
void bubbleSort(Type *const arr, int const n) {
    for(int i = n - 1; i > 0; --i) {
        Type max = arr[0];
        bool sorted = true;
        for(int j = 1; j <= i; ++j) {
            if(arr[j] < max) {
                arr[j - 1] = arr[j];
                sorted = false;
            } else {
                arr[j - 1] = max;
                max = arr[j];
            }
        }
        arr[i] = max;
        if(sorted) {
            break;
        }
    }
}

int main() {
    int arr[] = {7, 14, 12, 33, 5, 19};
    bubbleSort(arr, 6);
    for(int i = 0; i < 6; ++i) {
        std::cout << arr[i] << std::endl;
    }
}