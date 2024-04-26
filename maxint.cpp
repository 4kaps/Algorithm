#include <iostream>
using namespace std;

int max_val(int arr[], int a, int b){
    if(a == b){
        return arr[a];
    }else{
        int thismax = max_val(arr, a+1, b);
        if(arr[a] >= thismax){
            return arr[a];
        }else{
            return thismax;
        }
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
        cout << max_val(arr, 0, n-1) << '\n';
    }
}