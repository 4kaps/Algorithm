#include <iostream>
#include <cmath>
using namespace std;

int t, n;
unsigned long long k, tmp;

void hanoi(int n, int a, int b, int c, unsigned long long int k){
    if(n == 1){
        cout << a << " " << c << '\n';
        return;
    }else{
        tmp = pow(2, n-1);
        if(t > k){
            hanoi(n-1, a, c, b, k);
        }else if(t == k){
            cout << a << " " << c << '\n';
            return;
        }else{
            hanoi(n-1, b, a, c, k-tmp);
        }
    }
}

int main(){
    cin >> t;
    while(t--){
        cin >> n >> k;
        hanoi(n, 1, 2, 3, k);
    }
}
