#include <iostream>
#include <bits/stdc++.h>


using namespace std;

bool dfs(int vert, int cnt, vector<bool>& visited, vector<vector<int>>& graph, vector<int>& way) {
    visited[vert] = true;
    way[cnt - 1] = vert;
    if (cnt == graph.size()) {
        return true;
    }
    for (int i : graph[vert]) {
        if (!visited[i]) {
            if (dfs(i, cnt + 1, visited, graph, way)) {
                return true;
            }
        }
    }
    visited[vert] = false;
    return false;
}

bool hamiltonian_exists(vector<vector<int>>& graph, int s, int n) {
    vector<bool> visited(n);
    vector<int> way(n);
    visited[s] = true;
    if (dfs(s, 1, visited, graph, way)) {
        return true;
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int s = -1;
    vector<bool> visited(n);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        bool found = true;
        for (int i : graph[v]) {
            if (!visited[i]) {
                found = false;
                visited[i] = true;
                q.push(i);
            }
        }
        if (found) {
            s = v;
            break;
        }
    }
    if (s == -1) {
        cout << "NO";
    } else {
        if (hamiltonian_exists(graph, s, n)) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    }
    return 0;
}
