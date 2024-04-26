#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> memo;

int lcs(string x, string y, int m, int n){
    if(memo[m][n] != -1){
        return memo[m][n];
    }

    if((m == 0) || (n== 0)){
        memo[m][n] = 0;
    }else if(x[m-1] == y[n-1]){
        memo[m][n] = lcs(x, y, m-1, n-1) + 1;
    }else{
        memo[m][n] = max(lcs(x, y, m-1, n), lcs(x, y, m, n-1));
    }

    return memo[m][n];
}

int main(){
    int k;
    cin >> k;
    while(k--){
        string x, y;
        cin >> x >> y;

        memo = vector<vector<int>>(x.length() + 1, vector<int>(y.length() + 1, -1));

        if((x.length() == 1) && (y.length() == 1) && (x[0] == y[0])){
            cout << '1' << '\n';
        }else{
            cout << lcs(x, y, x.length(), y.length()) << '\n';
        }
    }
}