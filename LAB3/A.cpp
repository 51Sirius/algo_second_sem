#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void dfs(int vert, vector<int> &visited, vector<vector<int>> &graph, vector<int> &k_numbs, int numb, vector<int> &ks, bool *flag) {
    visited[vert] = true;
    k_numbs[vert-1] = numb;
    if (ks[vert]==1){
        *flag = false;
    }
    for (int i: graph[vert]) {
        if (!visited[i]) {
            dfs(i, visited, graph, k_numbs, numb, ks, flag);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> visited(n + 1, 0);
    vector<int> ks(n + 1, 0);
    vector<int> k_count(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> ks[i];
    }
    int count = 0;
    bool flag = true;
    vector<int> comps(n, 0);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, visited, graph, k_count, count + 1, ks, &flag);
            count++;
            if (!flag){
                comps[count-1] = 1;
                flag = true;
            }
        }
    }
    cout << count << endl;
    for (int i = 0; i < n; ++i) {
        cout << k_count[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < count; ++i) {
        cout << comps[i] << " ";
    }
    return 0;
}