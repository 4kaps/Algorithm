#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, m;
    int total = 0;
    cin >> n >> m;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
        total += arr[i];
    }

    int st = *max_element(arr, arr+n);
    int ed = total;
    int result = 0;

    while(st <= ed){
        int mid = (st + ed) / 2;
        int cnt = 0;
        total = 0;

        for(int i=0; i<n; i++){
            if(total + arr[i] > mid){
                cnt++;
                total = 0;
            }
            total += arr[i];
        }

        if(total != 0){
            cnt++;
        }

        if(cnt > m){
            st = mid + 1;
        }else{
            ed = mid - 1;
        }
    }

    cout << st << '\n';
}