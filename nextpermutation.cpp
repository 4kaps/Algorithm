#include <iostream>
#include <string>
#include <vector>
using namespace std;

int k, n;
string str;

void swap(vector<int> &v, int a, int b){
    int tmp = v[a];
    v[a] = v[b];
    v[b] = tmp;
}

bool next_permutation(vector<int> &v, int n){
    int i = n-1;
    while(i > 0 && v[i-1] >= v[i]){
        i--;
    }
    if(i <= 0){
        return false;
    }

    int j = n-1;
    while(v[i-1] >= v[j]){
        j--;
    }
    swap(v, i-1, j);
    j = n-1;

    while(i < j){
        swap(v, i, j);
        i++;
        j--;
    }
    
    return true;
}

int main(){
    cin >> k;
    while(k--){
        vector<int> intv;
        cin >> n >> str;
        for(int i=0; i<n; i++){
            int tmp = str[i];
            intv.push_back(tmp);
        }

        if(next_permutation(intv, n)){
            for(int i=0; i<n; i++){
                cout << char(intv[i]);
            }
        }else{
            for(int i=n-1; i>=0; i--){
                cout << char(intv[i]);
            }
        }
        cout << '\n';
    }
}