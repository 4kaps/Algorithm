#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    long long fac = 1;
    for(int i=n; i>0; i--){
        fac *= i;
    }
    
    int num;
    int result = 0;
    while(fac > 10){
        num = fac % 10;
        if(num != 0){
            break;
        }
        fac /= 10;
        result++;
    }
    
    cout << result;
}