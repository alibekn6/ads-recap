#include <iostream>
using namespace std;



class minHeap {
public:
    vector<int> arr;

    int parent(int i) {
        return (i - 1) / 2; 
    }

    int left(int i) {
        return 2 * i + 1; 
    }

    int right(int i) {
        return 2 * i + 2;
    }

    int getMin() {
        return arr[0];
    }


    // inserting element O (log n)
    void insert(int value) {
        arr.push_back(value);

        int index = arr.size() - 1;

        while (index > 0 && arr[index] < arr[parent(index)]) { // its not minheap so we must swap
            swap(arr[index], arr[parent(index)]);
            index = parent(index);
        }
    }

    void heapify(int i) {
        if (left(i) > arr.size() - 1) {
            return;
        }

        int j = left(i);
        if (right(i) < arr.size() && arr[right(i)] < arr[left(i)])
            j = right(i);



        if (arr[i] > arr[j]) {
            swap(arr[i], arr[j]);
            heapify(i);
        }




    }

    int extractMin() {

    }


};


int main () {

    // 


    return 0;
}