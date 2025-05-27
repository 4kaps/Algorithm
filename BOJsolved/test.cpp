#include <iostream>
#include <vector>
using namespace std;

int main() {
    string outputs[6] = {"ERROR", "ERROR", "INFO", "INFO", "INFO", "ERROR"};
    vector<pair<string, int>> p;

    p.push_back({outputs[0], 1});
    for(int i=1; i<6; i++){
        if(outputs[i] == outputs[i-1]){
            p.back().second++;
        }else{
            p.push_back({outputs[i], 1});
        }
    }

    for(int i=0; i<p.size(); i++){
        cout << p[i].first << "(" << p[i].second << "), ";
    }
    cout << '\n';
}
