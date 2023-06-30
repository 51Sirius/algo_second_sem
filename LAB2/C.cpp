#include <iostream>
#include <vector>

using namespace std;

void dfs(int vert, vector<int> &visited, vector<int> &graph, int n, int m) {
    visited[vert] = true;
    vector<int> adj = {vert - m, vert + m, vert - 1, vert + 1};
    if ((adj[2])%m == 0){
        adj[2] = 0;
    }
    if ((adj[3]-1)%m == 0){
        adj[3]=0;
    }
    for (int i: adj) {
        if (i <= n*m and i > 0) {
            if (!visited[i] and graph[i]) {
                dfs(i, visited, graph, n, m);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    char symb;
    vector<int> numbs(n * m+1, 0);
    vector<int> visited(n * m+1, 0);
    for (int i = 1; i <= n*m; i++) {
        cin >> symb;
        if (symb == '.') {
            numbs[i] = 1;
        }
    }
    int count = 0;
    for (int i = 1; i <= n*m; i++) {
        if (!visited[i] and numbs[i]) {
            dfs(i, visited, numbs, n, m);
            count++;
        }
    }
    cout << count;
    return 0;
}