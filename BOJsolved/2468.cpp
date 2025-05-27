#include <iostream>
#include <queue>
using namespace std;

const int MAX = 101;
int maps[MAX][MAX] = {0};
bool visited[MAX][MAX] = {false};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int>> q;

void bfs(int x, int y, int n, int a){
    visited[x][y] = true;
    q.push({x, y});
    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(nx >= 0 && ny >= 0 && nx < n && ny < n){
                if((maps[nx][ny] > a) && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    int mx = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> maps[i][j];
            if(maps[i][j] > mx){
                mx = maps[i][j];
            }
        }
    }

    int max_safe = 1;
    for(int j=1; j<mx; j++){
        int result = 0;
        for(int k=0; k<n; k++){
            for(int l=0; l<n; l++){
                visited[k][l] = false;
            }
        }
        for(int k=0; k<n; k++){
            for(int l=0; l<n; l++){
                if(!visited[k][l] && (maps[k][l] > j)){
                    bfs(k, l, n, j);
                    result++;
                }
            }
        }
        if(max_safe < result){
            max_safe = result;
        }
    }
    cout << max_safe << '\n';
}