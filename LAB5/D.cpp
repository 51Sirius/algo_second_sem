#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
//Шахматная доска белые-одна доля, черные-другая


bool dfs(int v, vector<int> &secret, vector<int> &matching, vector<bool> &visited, int n, int m) {
    if (visited[v] or secret[v] == 1)
        return false;
    vector<int> adj = {v - n, v + n, v - 1, v + 1};
    if (adj[0] < 1) {
        adj[0] = 0;
    }
    if (adj[1] > n * m) {
        adj[1] = 0;
    }
    if ((adj[2]) % n == 0) {
        adj[2] = 0;
    }
    if ((adj[3] - 1) % n == 0) {
        adj[3] = 0;
    }
    visited[v] = true;
    for (int to: adj) {
        if (to > 0 and secret[to] != 1) {
            if (matching[to] == -1 or dfs(matching[to], secret, matching, visited, n, m)) {
                matching[to] = v;
                return true;
            }
        }
    }


    return false;
}

int main() {
    int n, m, q;
    cin >> m >> n >> q;
    vector<int> matching(n * m + 1, -1);
    vector<bool> visited(n * m + 1, false);
    vector<int> secret(n * m + 1, 0);
    int u, v;
    for (int i = 0; i < q; ++i) {
        cin >> v >> u;
        secret[n * (v - 1) + u] = 1;
    }
    for (int i = 1; i <= n*m; ++i) {
        visited = vector<bool> (n * m + 1, false);
        dfs(i, secret, matching, visited, n, m);
    }
    int count = 0;
    for (int i = 1; i <= n * m; ++i) {
        if (matching[i] != -1 && secret[i] == 0) {
            count++;
        }
    }
    cout << count;
    return 0;
}