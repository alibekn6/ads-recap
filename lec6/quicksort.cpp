#include <iostream>
using namespace std;


int a[1000];

void quick_sort(int l, int r) {

    int p = a[(l + r) / 2];
    int i = l;
    int j = r;

    // j = 6


    //  [7, 2, 1, 6, 8, 5, 3, 4]
    // int p = 6
    // i = 0 j = 7
    
    /*
    

    */

    while (i < j) {
        while (a[i] < p) i++; // 7 < 6
        while (a[j] > p) j--; // 4 > 6
        

        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (l < j)
        quick_sort(l, j);
    if (i < r)
        quick_sort(i, r);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    quick_sort(0, n - 1);

    cout << "Sorted array:   ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}