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

int msort(int a[], int n){
    int result = 0;
    for(int i=1; i<n; i=2*i){
        for(int j=0; j<n-1; j+=2*i){
            int mid = min(i + j - 1, n - 1);
            int right = min(2 * i + j - 1, n - 1);
            result += merge(a, j, mid, right);
        }
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
        cout << msort(arr, n) << '\n';
    }
}