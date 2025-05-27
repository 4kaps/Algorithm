#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, m, result, total;

    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cin >> m;
    sort(arr, arr+n);

    int st = 0;
    int ed = arr[n-1];
    int mid = (st + ed) / 2;

    while(st <= ed){
        total = 0;
        mid = (st + ed) / 2;
        for(int i=0; i<n; i++){
            total += min(arr[i], mid);
        }

        if(total <= m){
            result = mid;
            st = mid + 1;
        }else{
            ed = mid - 1;
        }
    }

    cout << result << '\n';
}