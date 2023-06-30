#include <iostream>
#include <vector>

using namespace std;

const int INF = 1000001;


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a][b] = w;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int l = 1; l <= n; ++l) {
                if (abs(j - i) <= k and abs(l - i) <= k) {
                    graph[j][l] = min(graph[j][l], graph[j][i] + graph[i][l]);
                }
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        if (graph[a][b] != INF) {
            cout << graph[a][b] << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}