#include <iostream>
#include <vector>

using namespace std;

// A hybrid function combining binary search and insertion sort
void binary_insertion_sort(vector<int>& arr) {
    // Start traversing from the second element
    for (int i = 1; i < arr.size(); ++i) {
        int left = 0; // Initialize the left index
        int right = i - 1; // Initialize the right index
        int tmp = arr[i]; // Save the element currently to be inserted

        // Use binary search to find the insertion position
        while (left <= right) {
            int middle = (left + right) / 2; // Calculate the middle position
            if (arr[middle] < tmp) {
                left = middle + 1; // Insertion position is in the right half
            } else {
                right = middle - 1; // Insertion position is in the left half
            }
        }

        // Shift all elements to the right of the inserted element one position to the right
        for (int j = i - 1; j >= left; --j) {
            arr[j + 1] = arr[j]; // Move the current element one position to the right
        }
        arr[left] = tmp; // Insert the current element to the correct position
    }
}

int main() {
    vector<int> arr = {259, 38, 135, 97, 23, 22, 894, 1, 52, 87, 534, 0, 1254, 998, 621, 771};

    binary_insertion_sort(arr); // Sort the array using binary insertion sort

    cout << "After sorting: " << endl;
    for (int i : arr) {
        cout << i << " "; // Output the sorted array
    }
    cout << endl;

    return 0;
}
