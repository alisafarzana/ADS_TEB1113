#include <iostream>
using namespace std; // Allows omitting the 'std::' prefix

// Function to perform Bubble Sort on a raw array
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        bool swapped = false; 

        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
                swapped = true; 
            }
        }

        // Stop early if array is already sorted
        if (!swapped) {
            break;
        }
    }
}

// Helper function to print the array
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " "; // 'std::' removed
    }
    cout << endl; // 'std::' removed
}

int main() {
    int data[] = {74, 34, 24, 13, 22, 11, 90};
    int size = sizeof(data) / sizeof(data[0]);

    cout << "Unsorted array: ";
    printArray(data, size);

    bubbleSort(data, size);

    cout << "Sorted array:   ";
    printArray(data, size);

    return 0;
}
