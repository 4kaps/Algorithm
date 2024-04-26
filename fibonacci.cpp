#include <iostream>
using namespace std;

int k, n;
int dp[31];

int main(){
    dp[0] = 0;
    dp[1] = 1;
    cin >> k;
    while(k--){
        cin >> n;
        if(n >= 2){
            for(int i=2; i<=n; i++){
                dp[i] = dp[i-1] + dp[i-2];
            }
            cout << dp[n] << '\n';
        }else{
            cout << dp[n] << '\n';
        }
    }
}