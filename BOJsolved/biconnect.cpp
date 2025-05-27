#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <set>
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> low, disc;
vector<bool> articulation;
stack<pair<int, int>> st;
int times = 0;

void dfs(int u, int parent, set<int>& articulationPoints, int& biconnectedComponents) {
    disc[u] = low[u] = ++times;
    int children = 0;

    for (int v : adj[u]) {
        if (v == parent)
            continue;

        if (disc[v] == -1) {
            children++;
            st.push({u, v});
            dfs(v, u, articulationPoints, biconnectedComponents);
            low[u] = min(low[u], low[v]);

            if ((parent == -1 && children > 1) || (parent != -1 && low[v] >= disc[u])) {
                articulation[u] = true;
                articulationPoints.insert(u + 1);

                vector<pair<int, int>> biconnectedComponent;
                while (st.top() != make_pair(u, v)) {
                    biconnectedComponent.push_back(st.top());
                    st.pop();
                }
                biconnectedComponent.push_back(st.top());
                st.pop();

                biconnectedComponents++;
            }
        } else if (disc[v] < disc[u]) {
            low[u] = min(low[u], disc[v]);
            st.push({u, v});
        }
    }
}

void findArticulationPoints(int& biconnectedComponents) {
    low.assign(n, -1);
    disc.assign(n, -1);
    articulation.assign(n, false);
    times = 0;
    set<int> articulationPoints;

    for (int i = 0; i < n; ++i) {
        if (disc[i] == -1) {
            dfs(i, -1, articulationPoints, biconnectedComponents);
        }
    }

    int articulationCount = articulationPoints.size();
    
    cout << biconnectedComponents + 1 << '\n';

    cout << articulationCount << " ";
    for (int point : articulationPoints) {
        cout << point << " ";
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        adj.assign(n, vector<int>());

        for (int i = 0; i < n; ++i) {
            int k, m;
            cin >> k >> m;
            while (m--) {
                int v;
                cin >> v;
                adj[k - 1].push_back(v - 1);
            }
        }

        int biconnectedComponents = 0;
        findArticulationPoints(biconnectedComponents);
    }

    return 0;
}
