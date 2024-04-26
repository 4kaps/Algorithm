#include <iostream>
#include <algorithm>
using namespace std;

int dc(int arr[], int st, int ed){
    if(st == ed){
        return max(0, arr[st]);
    }else{
        int mid = (st + ed) / 2;
        int left = -1001;
        int right = -1001;
        int result = 0;

        for(int i=mid; i>=st; i--){
            result += arr[i];
            left = max(left, result);
        }
        result = 0;
        for(int i=mid+1; i<=ed; i++){
            result += arr[i];
            right = max(right, result);
        }

        int no_mid = max(dc(arr, st, mid), dc(arr, mid+1, ed));
        return max(left + right, no_mid);
    }
}

int main(){
    int k, n;
    cin >> k;
    while(k--){
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        cout << dc(arr, 0, n-1) << '\n';
    }
}