#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{
    int source, dest, weight;
    bool operator<(const Edge& other) const{
        return weight < other.weight;
    }
};

struct Sets{
    int parent, rank;
};

int finds(Sets sets[], int i){
    if(sets[i].parent != i){
        sets[i].parent = finds(sets, sets[i].parent);
    }
    return sets[i].parent;
}

void Union(Sets sets[], int x, int y){
    int xroot = finds(sets, x);
    int yroot = finds(sets, y);

    if(sets[xroot].rank < sets[yroot].rank){
        sets[xroot].parent = yroot;
    }else if(sets[xroot].rank > sets[yroot].rank){
        sets[yroot].parent = xroot;
    }else{
        sets[yroot].parent = xroot;
        sets[xroot].rank++;
    }
}

int kruskalMST(vector<Edge> &edges, int nodes){
    int totalWeight = 0;
    vector<Edge> result;
    sort(edges.begin(), edges.end());

    Sets *sets = new Sets[nodes];
    for(int i=0; i<nodes; i++){
        sets[i].parent = i;
        sets[i].rank = 0;
    }

    int edgeCount = 0;
    int i = 0;
    while(edgeCount < nodes - 1 && i < edges.size()){
        Edge nextEdge = edges[i++];
        int x = finds(sets, nextEdge.source);
        int y = finds(sets, nextEdge.dest);

        if(x != y){
            result.push_back(nextEdge);
            Union(sets, x, y);
            edgeCount++;
        }
    }

    for(const Edge &edge : result){
        totalWeight += edge.weight;
    }
    delete[] sets;
    return totalWeight;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int nodes;
        cin >> nodes;
        vector<Edge> edges;

        for (int i = 1; i <= nodes; i++) {
            int node, edgesCount;
            cin >> node >> edgesCount;
            for (int j = 0; j < edgesCount; j++) {
                int neighbor, weight;
                cin >> neighbor >> weight;
                if (node < neighbor) { 
                    edges.push_back({node, neighbor, weight});
                }
            }
        }
        int result = kruskalMST(edges, nodes + 1);
        cout << result << endl;
    }
    return 0;
}
