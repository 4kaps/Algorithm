#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long n;
    int k;
    vector<int> arr;
    cin >> n >> k;

    int five_cnt = 0;
    while(n > 0){
        int num;
        arr.push_back(num);
        if(num == 5){
            five_cnt++;
        }
        n /= 10;
    }

    int needed = k - five_cnt;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == 5){
            continue;
        }else{
            arr[i] = 5;
            needed--;
            if(needed <= 0){
                break;
            }
        }
    }

    for(int i=arr.size(); i>=0; i--){
        cout << arr[i];
    }
    cout << '\n';
}