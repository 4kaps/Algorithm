#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int lcs(string x, string y, int m, int n){
    if((m == 0) || (n== 0)){
        return 0;
    }else if(x[m] == y[n]){
        return lcs(x, y, m-1, n-1) + 1;
    }else{
        return max(lcs(x, y, m-1, n), lcs(x, y, m, n-1));
    }
}

int main(){
    int k;
    cin >> k;
    while(k--){
        string x, y;
        cin >> x >> y;
        if((x.length() == 1) && (y.length() == 1) && (x[0] == y[0])){
            cout << '1' << '\n';
        }else{
            cout << lcs(x, y, x.length()-1, y.length()-1) + 1 << '\n';
        }
    }
}