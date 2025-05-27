#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

const int INF = 1e9;

struct Node{
    int node;
    int weight;
};

int primMST(const vector<vector<Node>>& g){
    int nodes = g.size() - 1;
    vector<bool> visited(nodes + 1, false);
    vector<int> minWeight(nodes + 1, INF);
    int totalWeight = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int startNode = 1;
    pq.push({0, startNode});
    minWeight[startNode] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(visited[u]){
            continue;
        }
        visited[u] = true;
        totalWeight += minWeight[u];

        for(const auto& neighbor : g[u]){
            int v = neighbor.node;
            int weight = neighbor.weight;
            if(!visited[v] && (weight < minWeight[v])){
                minWeight[v] = weight;
                pq.push({weight, v});
            }
        }
    }
    return totalWeight;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int nodes;
        cin >> nodes;
        vector<vector<Node>> graph(nodes + 1);

        for(int i=1; i<=nodes; i++){
            int node, edges;
            cin >> node >> edges;
            for(int j=0; j<edges; j++) {
                int neighbor, weight;
                cin >> neighbor >> weight;
                graph[node].push_back({neighbor, weight});
                graph[neighbor].push_back({node, weight});
            }
        }
        int result = primMST(graph);
        cout << result << endl;
    }
}
