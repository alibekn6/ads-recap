// Binary search

#include <iostream>
#include <vector>
using namespace std;


/*
 * BINARY SEARCH - Time & Space Complexity


 * Time:  O(log n) - halves search space at each step
 * Space: O(1)     - iterative (uses constant space)
 *        O(log n) - recursive (call stack depth)
 *
 * Algorithm:


 * mid = l + (r - l) / 2  (avoids overflow)
 *
 * arr[mid] == x → return mid
 * arr[mid] < x  → search right half (l = mid + 1)
 * arr[mid] > x  → search left half (r = mid - 1)
 */




int binary_search(vector<int>& arr, int key) {
    int l = 0;
    int r = arr.size() - 1;

    while (l <= r) {

        int mid = l + (r - l) / 2;

        if (arr[mid] == key) return mid;
        if (arr[mid] > key) r = mid - 1;
        else l = mid + 1;
    }

    return -1;
}



int main() {
    vector<int> arr = {1, 4, 6, 7, 12, 91, 120, 152};

    int key = 91;

    int index = binary_search(arr, key);
    cout << (index != -1 ? "Found at index " + to_string(index) : "Not found") << "\n";


    return 0;
}