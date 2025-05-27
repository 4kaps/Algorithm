#include <iostream>
using namespace std;
#define MAX 1000001

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    bool sosu[MAX];
    for(int i=2; i<MAX; i++){
        sosu[i] = true;
    }
    sosu[0] = sosu[1] = false;

    for(int i=2; i*i<MAX; i++){
        if(sosu[i] == true){
            for(int j=i*2; j<=MAX; j+=i){
                sosu[j] = false;
            }
        }
    }

    while(true){
        int n, a, b;
        cin >> n;
        if(n == 0){
            break;
        }
        int result = 0;
        for(int i=0; i<=n/2; i++){
            int j = i;
            int k = n-i;
            if(sosu[j] && sosu[k]){
                result++;
            }
        }
        cout << result << '\n';
    }
}