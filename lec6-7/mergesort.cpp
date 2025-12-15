#include <iostream>
#include <vector>
#include <random>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    vector<int> leftArr(leftSize);  // Temp for left half
    vector<int> rightArr(rightSize); // Temp for right half

    for (int i = 0; i < leftSize; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < rightSize; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back
    int i = 0;     // Initial index of left subarray
    int j = 0;     // Initial index of right subarray
    int k = left;  // Initial index of merged array

    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }


    while (i < leftSize) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }


}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);


        merge(arr, left, mid, right);
    }
}

void printArray(vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

vector<int> generateRandomArray(int size, int minVal = 0, int maxVal = 10000) {
    vector<int> arr(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(minVal, maxVal);
    
    for (int i = 0; i < size; i++) {
        arr[i] = dis(gen);
    }
    
    return arr;
}

int main() {
    

    // vector<int> arr = generateRandomArray(1000000);

    vector<int> arr = {123, 10, 1, 56, 99, 3, 84, 100, 64, 14, 19, 98, 36, 31, 69, 14, 11};

    cout << "Original array: ";
    printArray(arr);

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array:   ";
    printArray(arr);

    return 0;
}