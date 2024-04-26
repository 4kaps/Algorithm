#include <iostream>
using namespace std;

int cnt;

void find(int a[], int low, int high, int& min, int& max){
    cnt++;
    int min1, min2, max1, max2;

    if(low == high){
        max = a[low];
        min = max;
    }else if(high == low + 1){
        if(a[low] < a[high]){
            min = a[low];
            max = a[high];
        }else{
            min = a[high];
            max = a[low];
        }
    }else{
        int mid = (low + high) / 2;
        find(a, low, mid, min1, max1);
        find(a, mid+1, high, min2, max2);

        if(min1 < min2){
            min = min1;
        }else{
            min = min2;
        }

        if(max1 > max2){
            max = max1;
        }else{
            max = max2;
        }
    }
}

int main(){
    int t;
    int arr[100], size;
    cin >> t;
    while(t--){
        cin >> size;
        cnt = 0;
        for(int i=0; i<size; i++){
            cin >> arr[i];
        }
        int min, max;
        find(arr, 0, size-1, min, max);
        cout << max << " " << min << " " << cnt << '\n';
    }
}