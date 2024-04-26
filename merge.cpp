#include <iostream>
using namespace std;

int merge(int a[], int low, int mid, int high){
    int i, j, k;
    int tmp[100];
    int result = 0;

    for(i=low; i<=high; i++){
        tmp[i] = a[i];
    }

    i = k = low;
    j = mid + 1;
    while(i<=mid && j<=high){
        result++;
        if(tmp[i] <= tmp[j]){
            a[k++] = tmp[i++];
        }else{
            a[k++] = tmp[j++];
        }
    }
    while(i<=mid){
        a[k++] = tmp[i++];
    }
    while(j<=high){
        a[k++] = tmp[j++];
    }

    return result;
}

int msort(int a[], int low, int high){
    int result = 0;
    if(low < high){
        int mid = (low + high) / 2;
        result += msort(a, low, mid);
        result += msort(a, mid+1, high);
        result += merge(a, low, mid, high);
    }
    return result;
}

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        cout << msort(arr, 0, n-1) << '\n';
    }
}