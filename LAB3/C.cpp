#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void dfs(int u, vector<bool> &visited, vector<vector<int>> &graph, stack<int> &order) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs(v, visited, graph, order);
        }
    }
    order.push(u);
}

void dfs2(int u, int k, vector<bool> &visited, vector<vector<int>> &rgraph, vector<int> &component) {
    visited[u] = true;
    component[u] = k;
    for (int v : rgraph[u]) {
        if (!visited[v]) {
            dfs2(v, k, visited, rgraph, component);
        }
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> graph(n+1), rgraph(n+1);
    vector<bool> visited(n+1, false);
    stack<int> order;
    vector<int> component(n+1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        rgraph[v].push_back(u);
    }
    for (int u = 1; u <= n; u++) {
        if (!visited[u]) {
            dfs(u, visited, graph, order);
        }
    }
    visited.assign(n+1, false);
    int count = 0;
    while (!order.empty()) {
        int u = order.top();
        order.pop();
        if (!visited[u]) {
            dfs2(u, count, visited, rgraph, component);
            count++;
        }
    }
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        if (component[u] == component[v]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}