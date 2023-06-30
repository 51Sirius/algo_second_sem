#include <iostream>
#include <vector>
#include <limits>
#include "queue"

using namespace std;

const int INF = numeric_limits<int>::max();

void top_sort(int n, vector<vector<int>> graph, vector<int> &in_degree, queue<int> &new_order) {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
            new_order.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 1; i <= n; ++i) {
            if (graph[u][i] != INF) {
                in_degree[i]--;
                if (in_degree[i] == 0) {
                    q.push(i);
                    new_order.push(i);
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int s, t;
    cin >> s >> t;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
    vector<int> indegree(n + 1, 0);
    vector<int> d(n + 1, INF);
    queue<int> p;
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a][b] = w;
        indegree[b]++;
    }
    d[s] = 0;
    top_sort(n, graph, indegree, p);
    int u = p.front();
    p.pop();
    while (u != s) {
        u = p.front();
        p.pop();
    }
    while (!p.empty()) {
        for (int j = 1; j <= n; ++j) {
            if (graph[u][j] != INF) {
                if (d[u] != INF) {
                    d[j] = min(d[j], d[u] + graph[u][j]);
                }

            }
        }
        u = p.front();
        p.pop();
    }
    if (d[t] != INF) {
        cout << d[t];
    } else {
        cout << -1;
    }
    return 0;
}