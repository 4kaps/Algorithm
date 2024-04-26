#include <iostream>
using namespace std;

int k, m, n, s, t;
int visited[8][8];
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isValid(int x, int y){
    if(0 <= x && x < n && 0 <= y && y < m && visited[y][x] == -1){
        return true;
    }else{
        return false;
    }
}

bool tour(int cnt, int x, int y){
    if(cnt == m * n){
        visited[y][x] = cnt - 1;
        return true;
    }
    int mv = 8;
    int mc = -1;

    for(int i=0; i<8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        int val = 0;          
        if(isValid(nx, ny)){
            for(int j=0; j<8; j++){
                int tx = nx + dx[j];
                int ty = ny + dy[j];
                if(isValid(tx, ty)){
                    val++;
                }
            }
            if(mv > val){
                mv = val;
                mc = i;
            }
        }
    }   
    int nx = x + dx[mc];
    int ny = y + dy[mc];
    int val = 0;

    if(isValid(nx, ny)){
        visited[y][x] = cnt - 1;
        if(tour(cnt+1, nx, ny)){
            return true;
        }else{
            visited[y][x] = -1;
        }
    }
    return false;
}

int main(){
    cin >> k;
    while(k--){
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                visited[i][j] = -1;
            }
        }

        cin >> m >> n >> s >> t;
        visited[s-1][t-1] = 0;
        
        if(tour(1, t-1, s-1)){
            cout << 1 << '\n';
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    cout << visited[i][j] + 1 << " ";
                }
                cout << '\n';
            }
        }else{
            cout << 0 << '\n';
        }
    }
}