#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

bool visited[601][601] = {0,};
char maps[601][601];
int result = 0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y, int mx, int my){
    visited[x][y] = true;
    if(maps[x][y] == 'P'){
        result++;
    }
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < mx && ny < my){
            if((!visited[nx][ny] && maps[nx][ny] != 'X')){
                dfs(nx, ny, mx, my);
            }
        }
    }
}

int main(){
    int n, m;
    int sx, sy;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> maps[i][j];
            if(maps[i][j] == 'I'){
                sx = i;
                sy = j;
            }
        }
    }

    dfs(sx, sy, n, m);
    if(result == 0){
        cout << "TT" << '\n';
    }else{
        cout << result << '\n';
    }
}