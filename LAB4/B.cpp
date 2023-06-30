#include <iostream>
#include <vector>

using namespace std;

const int INF = 10000;


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n+1, INF));
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a][b] = w;
        graph[b][a] = w;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int l = 1; l <= n; ++l) {
                graph[j][l] = min(graph[j][l], graph[j][i] + graph[i][l]);
            }
        }
    }
    int diameter = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] != INF and i != j) {
                diameter = max(diameter, graph[i][j]);
            }
        }
    }
    cout << diameter;
    return 0;
}