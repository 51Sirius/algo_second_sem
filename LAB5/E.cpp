#include <iostream>
#include <queue>

using namespace std;

bool bfs(int n, vector<vector<int>> &H, vector<int> &root) {
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && H[u][v] > 0) {
                q.push(v);
                root[v] = u;
                visited[v] = true;
                if (v == n) {
                    return true;
                }
            }
        }
    }
    return false;
}

int fordik(int n, vector<vector<int>> &H) {
    int answer = 0;
    vector<int> root(n + 1, 0);
    while (bfs(n, H, root)) {
        int pathFlow = 200000;
        for (int v = n; v != 1; v = root[v]) {
            int u = root[v];
            pathFlow = min(pathFlow, H[u][v]);
        }
        for (int v = n; v != 1; v = root[v]) {
            int u = root[v];
            H[u][v] -= pathFlow;
            H[v][u] += pathFlow;
        }
        answer += pathFlow;
    }
    return answer;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> H(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        H[u][v] = c;
    }
    cout << fordik(n, H);
    return 0;
}