#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1001;
int maps[MAX][MAX] = {-1};
int resmaps[MAX][MAX] = {0};
bool visited[MAX][MAX] = {false};
queue<pair<int, int>> q;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void bfs(int x, int y, int n, int m){
    q.push({x, y});
    visited[x][y] = true;
    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                if((maps[nx][ny] == 1) && !visited[nx][ny]){
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                    resmaps[nx][ny] = resmaps[curx][cury] + 1;
                }
            }
        }
    }
}

int main(){
    int x, y, n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> maps[i][j];
            if(maps[i][j] == 2){
                x = i;
                y = j;
            }
        }
    }

    bfs(x, y, n, m);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(maps[i][j] == 1 && !visited[i][j]){
                resmaps[i][j] = -1;
            }
            cout << resmaps[i][j] << " ";
        }
        cout << '\n';
    }
}
