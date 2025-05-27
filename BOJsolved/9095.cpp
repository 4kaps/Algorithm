#include <iostream>
using namespace std;

int dp[11] = {0,};

int main(){
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        if(n < 4){
            cout << dp[n] << '\n';
        }else{
            for(int i=4; i<=n; i++){
                dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
            }
            cout << dp[n] << '\n';
        }
    }
}

// dp[i] = dp[i-1] + dp[i-2] + dp[i-3]