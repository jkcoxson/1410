// Jackson Coxson

#ifndef SORTS_HPP
#define SORTS_HPP

#include <algorithm>

class Sorts {
  public:
    void bubble(int* pArray, int length) {
        for (int i = 0; i < length - 1; ++i) {
            // Last i elements are already in place
            for (int j = 0; j < length - 1 - i; ++j) {
                if (pArray[j] > pArray[j + 1]) {
                    std::swap(pArray[j], pArray[j + 1]);
                }
            }
        }
    }

    // Insertion Sort implementation
    void insertion(int* pArray, int length) {
        for (int i = 1; i < length; ++i) {
            int key = pArray[i];
            int j   = i - 1;
            // Move elements of pArray[0..i-1], that are greater than key,
            // to one position ahead of their current position
            while (j >= 0 && pArray[j] > key) {
                pArray[j + 1] = pArray[j];
                j             = j - 1;
            }
            pArray[j + 1] = key;
        }
    }

    void quick(int* pArray, int length) {
        // Check if the array has elements to sort
        if (length > 0) {
            quickSortRecursive(pArray, 0, length - 1);
        }
    }

  private:
    // Quick Sort helper function for partitioning
    int partition(int* pArray, int low, int high) {
        int pivot = pArray[high]; // Choosing the last element as the pivot
        int i     = (low - 1);    // Index of smaller element

        for (int j = low; j <= high - 1; j++) {
            // If current element is smaller than the pivot
            if (pArray[j] <= pivot) {
                i++; // Increment index of smaller element
                std::swap(pArray[i], pArray[j]);
            }
        }
        std::swap(pArray[i + 1], pArray[high]);
        return (i + 1);
    }

    // Quick Sort recursive function
    void quickSortRecursive(int* pArray, int low, int high) {
        if (low < high) {
            // pi is partitioning index, pArray[pi] is now at the right place
            int pi = partition(pArray, low, high);
            // Separately sort elements before and after partition
            quickSortRecursive(pArray, low, pi - 1);
            quickSortRecursive(pArray, pi + 1, high);
        }
    }
};
#endif
