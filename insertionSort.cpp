#include <iostream>
#include <vector>

template <typename T>
void insertionSort(std::vector<T> &inputArray) {
    for (int i = 0; i < inputArray.size(); i++) {
        int j = i - 1;
        T currElem = inputArray.at(i);

        std::cout << "Current element: " << currElem << std::endl;
        std::cout << "Array before sorting step " << i + 1 << ": ";
        for (const auto &num : inputArray) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        while (j >= 0 && inputArray.at(j) > currElem) {
            inputArray.at(j + 1) = inputArray.at(j);
            j = j - 1;
        }
        inputArray.at(j + 1) = currElem;

        std::cout << "Array after sorting step " << i + 1 << ": ";
        for (const auto &num : inputArray) {
            std::cout << num << " ";
        }
        std::cout << std::endl << std::endl;
    }
}

int main() {
    std::vector<int> nums = {5, 2, 9, 1, 5, 6};
    std::cout << "Original array: ";
    for (const auto &num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    insertionSort(nums);

    std::cout << "Sorted array: ";
    for (const auto &num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
