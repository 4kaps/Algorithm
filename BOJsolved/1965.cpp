#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[1010];
    int dp[1010];

    for(int i=0; i<n; i++){
        cin >> arr[i];
        dp[i] = 1;
    }

    int cur = n-1;
    for(int i=n-2; i>=0; i--){
        if(arr[i] < arr[cur]){
            dp[i] = dp[cur] + 1;
            cur = i;
        }
    }

    int mx = *max_element(dp, dp + n);

    cout << mx << '\n';
}