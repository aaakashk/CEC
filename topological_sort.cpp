#include <iostream>
#include <list>
#include <stack>

using namespace std;
class graph {
    int v;
    list<int>* adj;
    void toposort(int v, bool visited[], stack<int>& Stack);

   public:
    graph(int v);
    void addEdges(int v, int d);
    void topologicalsort();
};
graph::graph(int v) {
    this->v = v;
    adj = new list<int>[v];
}
void graph::addEdges(int v, int d) {
    adj[v].push_back(d);
}
void graph::toposort(int v, bool visited[], stack<int>& Stack) {
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            toposort(*i, visited, Stack);
    Stack.push(v);
}
void graph::topologicalsort() {
    stack<int> Stack;
    bool* visited = new bool[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;
    for (int i = 0; i < v; i++)
        if (visited[i] == false)
            toposort(i, visited, Stack);
    while (Stack.empty() == false) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
    delete[] visited;
}
int main() {
    graph g(6);
    g.addEdges(5, 2);
    g.addEdges(5, 0);
    g.addEdges(4, 0);
    g.addEdges(4, 1);
    g.addEdges(2, 3);
    g.addEdges(3, 1);
    cout << "After applying topological sort\n";
    g.topologicalsort();
    return 0;
}