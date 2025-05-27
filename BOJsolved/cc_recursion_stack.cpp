#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maps[1001][1001];
bool visited[1001];

int dfs(int n, int size){
    visited[n] = true;
    int cnt = 1;
    for(int i=1; i<=size; i++){
        if(maps[n][i] != 0 && !visited[i]){
            cnt += dfs(i, size);
        }
    }
    return cnt;
}

int main(){
    int t, n, a, b, c;
    cin >> t;
    while(t--){
        for(int i=0; i<1001; i++){
            for(int j=0; j<1001; j++){
                maps[i][j] = 0;
            }
            visited[i] = false;
        }

        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a >> b;
            for(int j=0; j<b; j++){
                cin >> c;
                maps[a][c] = 1;
            }
        }

        vector<int> v;
        for(int i=1; i<=n; i++){
            if(!visited[i]){
                v.push_back(dfs(i, n));
            }
        }

        sort(v.begin(), v.end());
        cout << v.size() << " ";
        for(int i=0; i<v.size(); i++){
            cout << v[i] << " ";
        }
        cout << '\n';
    }
}