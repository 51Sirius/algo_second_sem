#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int from;
    int to;
    int weight;
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N, M, Q, s;
    cin >> N >> M >> Q >> s;
    vector<Edge> edges(2 * (M + 1));
    for (int i = 1; i <= M; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[2 * i - 1] = {a, b, w};
        edges[2 * i] = {b, a, w};
    }
    vector<int> dist(N + 1, INF);
    dist[s] = 0;
    int flag;
    for (int i = 1; i < N; i++) {
        flag = 0;
        for (int j = 1; j <= 2 * M; j++) {
            int u = edges[j].from;
            int v = edges[j].to;
            int w = edges[j].weight;
            if (dist[u] < INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                flag = 1;
            }
        }
        if (flag==0){
            break;
        }
    }

    for (int i = 0; i < Q; ++i) {
        int b;
        cin >> b;
        if (dist[b] < INF) {
            cout << dist[b] << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}