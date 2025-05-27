#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, x;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cin >> x;

    sort(arr, arr+n);

    int i = 0;
    int j = n-1;
    int result = 0;
    while(i < j){
        if(arr[i] + arr[j] == x){
            result++;
            i++;
            j--;
        }else if(arr[i] + arr[j] > x){
            j--;
        }else{
            i++;
        }
    }

    cout << result << '\n';
}