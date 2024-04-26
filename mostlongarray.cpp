#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int k, n;
    cin >> k;
    while(k--){
        cin >> n;
        int arr[n];
        int tmp = 0; 
        int result = 0;

        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        for(int i=0; i<n; i++){
            if((i != n-1) && (arr[i] <= arr[i+1])){
                tmp++;
            }else{
                result = max(result, tmp);
                tmp = 0;
            }
        }

        cout << result + 1 << '\n';
    }
}