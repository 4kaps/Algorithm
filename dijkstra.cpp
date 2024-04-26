#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

struct Edge{
    int to;
    int weight;
};

vector<int> dijkstra(int st, vector<vector<Edge>>& g){
    int n = g.size();
    vector<int> dist(n, INT_MAX);
    dist[st] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, st});

    while(!pq.empty()){
        int u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();

        if(dist_u > dist[u]){
            continue;
        }

        for(const Edge& e : g[u]){
            int v = e.to;
            int weight = e.weight;
            if(dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int buildTree(int st, const vector<int>& dist, vector<vector<Edge>>& g){
    int n = g.size();
    int totalWeight = 0;
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(st);
    visited[st] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(const Edge& e : g[u]){
            int v = e.to;
            int weight = e.weight;
            if(dist[v] == dist[u] + weight){
                totalWeight += weight;
                if(!visited[v]){
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }
    return totalWeight;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<Edge>> graph(n+1);
        for(int i=1; i<=n; ++i){
            int node, edges;
            cin >> node >> edges;
            for(int j=0; j<edges; ++j){
                int to, weight;
                cin >> to >> weight;
                graph[node].push_back({to, weight});
            }
        }
        int startNode = 1;
        vector<int> shortestPath = dijkstra(startNode, graph);
        int result = buildTree(startNode, shortestPath, graph);
        cout << result << '\n';
    }
}
