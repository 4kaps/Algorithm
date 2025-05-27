#include <iostream>
using namespace std;

int main(){
    int k, n;
    cin >> k;
    while(k--){
        int arr[30] = {0};
        string key[30] = {""};
        cin >> n;

        string str;
        string keys;
        for(int i=0; i<n; i++){
            bool found = false;
            cin >> str >> keys;
            for(int j=0; j<30; j++){
                if(keys == key[j]){
                    found = true;
                    arr[j]++;
                    break;
                }
            }
            if(!found){
                for(int j=0; j < 30; j++){
                    if (key[j] == "") {
                        key[j] = keys;
                        arr[j]++;
                        break;
                    }
                }
            }
        }

        int result = 1;
        for(int i=0; i<30; i++){
            if(arr[i] != 0){
                result *= (arr[i] + 1);
            }
        }

        cout << result - 1 << '\n';
    }
}