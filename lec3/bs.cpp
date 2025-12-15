#include <iostream>
#include <vector>
using namespace std;


int binary_search(vector<int>& arr, int key) {
    int left = 0;
    int right = arr.size();

    

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] > key) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1;
}