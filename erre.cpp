#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000

vector<int> adj[MAXN]; // 인접 리스트
vector<vector<int>> bcc; // biconnected components 저장
int low[MAXN], num[MAXN], parent[MAXN];
int counter, bcc_count;
stack<pair<int,int>> st;

// Tarjan의 알고리즘을 사용하여 biconnected component 찾기
void dfs(int u) {
    low[u] = num[u] = counter++;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (num[v] == -1) {
            st.push({u, v});
            parent[v] = u;
            dfs(v);

            if (low[v] >= num[u]) {
                vector<int> component;
                while (true) {
                    int x = st.top().first;
                    int y = st.top().second;
                    st.pop();
                    component.push_back(x);
                    component.push_back(y);
                    if (x == u && y == v) break;
                }
                sort(component.begin(), component.end());
                component.erase(unique(component.begin(), component.end()), component.end());
                bcc.push_back(component);
            }

            low[u] = min(low[u], low[v]);
        } else if (v != parent[u] && num[v] < num[u]) {
            st.push({u, v});
            low[u] = min(low[u], num[v]);
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n;

        // 초기화
        for (int i = 0; i < MAXN; i++) {
            adj[i].clear();
            low[i] = -1;
            num[i] = -1;
            parent[i] = -1;
        }
        counter = 0;
        bcc_count = 0;
        bcc.clear();
        while (!st.empty()) st.pop();

        // 그래프 입력 받기
        for (int i = 0; i < n; i++) {
            int u, k;
            cin >> u >> k;
            for (int j = 0; j < k; j++) {
                int v;
                cin >> v;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        // Tarjan의 알고리즘 실행
        for (int i = 1; i <= n; i++) {
            if (num[i] == -1) {
                dfs(i);
            }
        }

        // 출력: biconnected components의 개수와 각 component의 크기 출력
        cout << bcc.size() << endl;
        for (auto component : bcc) {
            cout << component.size() / 2 << " ";
            for (int i = 0; i < component.size(); i += 2) {
                cout << component[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
