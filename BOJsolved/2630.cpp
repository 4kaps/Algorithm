#include <iostream>
using namespace std;

bool scans(int a, int b, int n);

int maps[128][128];
int blue = 0;
int white = 0;

void cut(int a, int b, int n){
    if(!scans(a, b, n)){
        cut(a, b, n/2);
        cut(a + n/2, b, n/2);
        cut(a, b + n/2, n/2);
        cut(a + n/2, b + n/2, n/2);
    }
}

bool scans(int a, int b, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(maps[a][b] != maps[a+i][b+j]){
                return false;
            }
        }
    }

    if(maps[a][b] == 1){
        blue++;
        return true;
    }else{
        white++;
        return true;
    }
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> maps[i][j];
        }
    }

    cut(0, 0, n);

    cout << white << '\n' << blue << '\n';
}