#include <iostream>
#include <vector>
#include <numeric> 
using namespace std;

vector<double> gaussElimin(vector<vector<double>>& a, vector<double>& b){
    int n = b.size();
    for(int k = 0; k < n - 1; ++k){
        for(int i = k + 1; i < n; ++i){
            if(a[i][k] != 0.0){
                double lam = a[i][k] / a[k][k];
                for(int j = k + 1; j < n; ++j){
                    a[i][j] -= lam * a[k][j];
                }
                b[i] -= lam * b[k];
            }
        }
    }
    vector<double> x(n);
    for(int k = n - 1; k >= 0; --k){
        x[k] = (b[k] - inner_product(a[k].begin() + k + 1, a[k].end(), x.begin() + k + 1, 0.0)) / a[k][k];
    }
    return x;
}

int main(){
    vector<vector<double>> a = {{1, 1, 2},
                                {2, 4, -3},
                                {3, 6, -5}};
    vector<double> b = {9, 1, 0};
    vector<double> x = gaussElimin(a, b);
    for(double val : x){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
