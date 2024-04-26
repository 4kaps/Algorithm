#include <iostream>
#include <vector>

using namespace std;
int comparison = 0;
int swaps = 0;

void shellSort(vector<int>& arr) {
    int s = arr.size();
    int gap = s / 2;
    while(gap > 0){
        for(int i=gap; i<s; i++){
            int tmp = arr[i];
            int j = i;
            for(j=i; j >= gap; j-=gap){
                comparison++;
                if(arr[j-gap] > tmp){
                    arr[j] = arr[j-gap];
                    swaps++;
                }
            }
            arr[j] = tmp;
        }
        gap /= 2;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        comparison = 0;
        swaps = 0;
        shellSort(arr);

        cout << comparison << " " << swaps << endl;
    }

    return 0;
}