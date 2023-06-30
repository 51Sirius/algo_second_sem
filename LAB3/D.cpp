#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


void top_sort(int n, vector<int> *graph, vector<int> &in_degree, vector<int> &new_order) {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }
    int tmp =1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        new_order[u] = tmp++;
        for (int v : graph[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> graph[n + 1];
    vector<int> degree(n + 1, 0);
    vector<int> new_order(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        degree[v]++;
    }
    top_sort(n, graph, degree, new_order);
    for (int i = 1; i <= n; ++i) {
        cout << new_order[i] << ' ';
    }
    return 0;
}