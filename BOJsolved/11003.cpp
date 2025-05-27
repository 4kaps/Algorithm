#include <iostream>
#include <deque>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, l;
    cin >> n >> l;

    deque<pair<int, int>> dq;
    int num;
    for(int i=0; i<n; i++){
        cin >> num;
        while(!dq.empty() && dq.back().first > num){
            dq.pop_back();
        }

        dq.push_back({num, i});
        if(dq.front().second <= i-l){
            dq.pop_front();
        }

        cout << dq.front().first << " ";
    }
}