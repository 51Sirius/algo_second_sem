#include <iostream>
#include <vector>

using namespace std;

bool dfs(int vert, int parent, vector<int> &visited, vector<vector<int>> &graph) {
    visited[vert] = true;
    for (int i : graph[vert]) {
        if (!visited[i]) {
            if (dfs(i, vert, visited, graph)) return true;
        } else if (i != parent) return true;
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bool flag = false;
    vector<int> visited(n+1, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, NULL, visited, graph)) {
                flag = true;
            }
        }
    }
    if (flag) cout << "YES";
    else cout << "NO";
    return 0;
}