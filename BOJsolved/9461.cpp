#include <iostream>
using namespace std;

long long dp[100];

int main(){
    dp[0] = dp[1] = dp[2] = 1;
    dp[3] = dp[4] = 2;
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        if(n < 6){
            cout << dp[n-1] << '\n';
        }else{
            for(int i=5; i<n; i++){
                dp[i] = dp[i-1] + dp[i-5];
            }
            cout << dp[n-1] << '\n';
        }
    }
}

// n = 9, 8 + 4
// n = 10, 9 + 5
// n = 11, 10 + 6
// n = 12, 11 + 7
// n = 13, 12 + 8