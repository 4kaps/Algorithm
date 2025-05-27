#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector<pair<int, pair<int, int>>> v;
    int k, n, space, a, b;
    cin >> k;
    while(k--){
        cin >> n >> space;
        
        for(int i=0; i<n; i++){
            cin >> a >> b;
            v.push_back({b/a, {a, b}}); 
        }
        sort(v.begin(), v.end());

        int result = 0;

        while(v.size() > 0){
            if(space - v.back().second.first >= 0){
                space -= v.back().second.first;
                result += v.back().second.second;
                v.pop_back();
            }else{
                v.pop_back();
            }
        }
        cout << result << '\n';
    }
}
