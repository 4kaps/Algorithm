#include <iostream>
typedef long long int Type;
using namespace std;
int k, n;

typedef struct Matrix1{
    Type fibo[2][2];
}
Matrix1;

Matrix1 x(Matrix1 a, Matrix1 b){
    Matrix1 c;
    c.fibo[0][0] = (a.fibo[0][0] * b.fibo[0][0] + a.fibo[0][1] * b.fibo[1][0]) % 10000;
    c.fibo[1][0] = (a.fibo[1][0] * b.fibo[0][0] + a.fibo[1][1] * b.fibo[1][0]) % 10000;
    c.fibo[0][1] = (a.fibo[0][0] * b.fibo[0][1] + a.fibo[0][1] * b.fibo[1][1]) % 10000;
    c.fibo[1][1] = (a.fibo[1][0] * b.fibo[0][1] + a.fibo[1][1] * b.fibo[1][1]) % 10000;
    return c;
}

Matrix1 power(Matrix1 a, int n){
    if(n > 1){
        a = power(a, n/2);
        a = x(a, a);
        if(n % 2 == 1){
            Matrix1 b = {1, 1
                        ,1, 0};
            a = x(a, b);
        }
    }
    return a;
}

int main(){
    cin >> k;
    while(k--){
        cin >> n;
        Matrix1 a = {1, 1
                    ,1, 0};
        a = power(a, n);
        if(n != 0){
            cout << a.fibo[0][1] % 1000 << '\n';
        }else{
            cout << '0' << '\n';
        };
    }
}
