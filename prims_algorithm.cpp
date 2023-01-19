#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

#define Inf 1e9

typedef pair<int, int> Pair;
class Graph {
    int v;
    list<pair<int, int>>* adj;

   public:
    Graph(int v);
    void addEdges(int u, int v, int w);
    void primsAlgo();
};
Graph::Graph(int v) {
    this->v = v;
    adj = new list<Pair>[v];
}
void Graph::addEdges(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
void Graph::primsAlgo() {
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;  // min-heap.
    int src = 0;
    vector<int> dist(v, Inf);
    vector<int> parent(v, -1);
    vector<bool> visited(v, false);
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u] == true) {
            continue;
        }
        visited[u] = true;
        list<pair<int, int>>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {
            int v = (*i).first;
            int weight = (*i).second;
            if (visited[v] == false && dist[v] > weight) {
                dist[v] = weight;
                pq.push(make_pair(dist[v], v));
                parent[v] = u;
            }
        }
    }
    for (int i = 1; i < v; ++i)
        printf("%d - %d\n", parent[i], i);
}
int main() {
    Graph g(5);
    g.addEdges(0, 1, 2);
    g.addEdges(0, 2, 1);
    g.addEdges(1, 2, 1);
    g.addEdges(1, 0, 2);
    g.addEdges(2, 0, 1);
    g.addEdges(2, 1, 1);
    g.addEdges(2, 4, 2);
    g.addEdges(2, 3, 2);
    g.addEdges(3, 4, 1);
    g.addEdges(3, 2, 2);
    g.primsAlgo();
    return 0;
}