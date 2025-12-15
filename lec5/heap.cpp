#include <iostream>

using namespace std;

class MinHeap {
public:
    vector<int> a;

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
        return a[0];
    }

    // Insert element - O(log n)
    void insert(int k) {
        a.push_back(k);
        int index = a.size() - 1;

        // Heapify up: bubble up the element
        while (index > 0 && a[index] < a[parent(index)]) {
            swap(a[index], a[parent(index)]);
            index = parent(index);
        }
        
    }

    // Heapify down - O(log n)
    void heapify(int i) {
        if (left(i) > a.size() - 1)
            return;

        // Find smallest among node and its children
        int j = left(i);
        if (right(i) < a.size() && a[right(i)] < a[left(i)])
            j = right(i);

        // If parent is greater than smallest child, swap and continue
        if (a[i] > a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    // Extract minimum element - O(log n)
    int extractMin() {
        int root_value = getMin();

        // Replace root with last element
        swap(a[0], a[a.size() - 1]);
        a.pop_back();

        // Heapify down from root
        if (a.size() > 0)
            heapify(0);

        return root_value;
    }
};

int main() {
    int n, x;
    cin >> n;
    MinHeap *heap = new MinHeap();

    // Insert n elements
    for (int i = 0; i < n; i++) {
        cin >> x;
        heap->insert(x);
    }

    // Extract all elements (sorted order)
    for (int i = 0; i < n; i++)
        cout << heap->extractMin() << " ";

    return 0;
}