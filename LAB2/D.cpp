#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int bfs(int from, int to, vector<vector<int>> &graph, int *d){
    queue<int> q;
    int u;
    d[from]= 0;
    q.push(from);
    while (!q.empty()){
        u = q.front();
        q.pop();
        for (int i : graph[u]) {
            if (d[i] == -1){
                d[i] = d[u] +1;
                q.push(i);
            }
        }
    }
    return d[to];
}

int main() {
    int n, m;
    cin >> n >> m;
    int u, v;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int d[n+1];
    cin >> u >> v;
    for (int i = 0; i <= n; ++i) {
        d[i] = -1;
    }
    cout << bfs(u, v, graph, d);
    return 0;
}