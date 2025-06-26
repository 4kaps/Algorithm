#include <string>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land) {
    int n = land.size();
    int m = land[0].size();
    
    vector<string> visited(n, string(m, '0')); // 방문 여부: '0' or '1'
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    vector<int> columnOil(m, 0); // 각 열별 석유량 저장

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (land[y][x] == 1 && visited[y][x] == '0') {
                // 덩어리 하나 탐색 시작
                stack<pair<int, int>> s;
                s.push({y, x});
                visited[y][x] = '1';

                int oil = 0;
                set<int> cols; // 이 덩어리가 포함하는 열들

                while (!s.empty()) {
                    auto [cy, cx] = s.top(); s.pop();
                    oil++;
                    cols.insert(cx);

                    for (int i = 0; i < 4; i++) {
                        int ny = cy + dy[i];
                        int nx = cx + dx[i];
                        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                        if (land[ny][nx] == 1 && visited[ny][nx] == '0') {
                            visited[ny][nx] = '1';
                            s.push({ny, nx});
                        }
                    }
                }

                // 이 덩어리에 연결된 모든 열에 석유량 추가
                for (int col : cols) {
                    columnOil[col] += oil;
                }
            }
        }
    }

    // 열 중 가장 많은 석유량
    return *max_element(columnOil.begin(), columnOil.end());
}
