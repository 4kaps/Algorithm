#include <iostream>
using namespace std;

void insertionSort(int arr[], int n, int &comparisons, int &swaps) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++;  
            arr[j + 1] = arr[j];
            swaps++; 
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        int comparisons = 0;
        int swaps = 0;
        
        insertionSort(arr, n, comparisons, swaps);
        
        cout << comparisons << " " << swaps << endl;
    }
    
    return 0;
}
