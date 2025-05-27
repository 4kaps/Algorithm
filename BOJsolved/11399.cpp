#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n);

    int result = 0;
    for(int i=0; i<n; i++){
        result += arr[i] * (n - i);
    }

    cout << result << '\n';
}