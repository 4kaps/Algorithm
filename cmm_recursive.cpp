#include <iostream>
#include <climits>
#include <vector>
using namespace std;
vector<vector<int>> memo;

int cmm(int arr[], int i, int j){
    if(i == j){
        return 0;
    }else if(memo[i][j] != -1){
        return memo[i][j];
    }else{
        int minval = INT_MAX;
        for(int k=i; k<j; k++){
            int val = cmm(arr, i, k) + cmm(arr, k+1, j) + arr[i-1] * arr[k] * arr[j];
            if(val < minval){
                minval = val;
            }
        }
        memo[i][j] = minval;
        return minval;
    }
}

int main(){
    int k, n;
    cin >> k;
    while(k--){
        cin >> n;
        int arr[n+1];
        memo.clear();
        memo.resize(n+1, vector<int>(n+1, -1));
        for(int i=0; i<=n; i++){
            cin >> arr[i];
        }
        cout << cmm(arr, 1, n) << '\n';
    }
}