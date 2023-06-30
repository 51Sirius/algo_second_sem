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

void func(int k){
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m+1);
    for (int ii = 1; ii <= m; ii++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[ii] = {a, b, w};
    }
    vector<int> dist(n+1, INF);
    vector<int> parents(n+1, -1);
    dist[1] = 0;
    int flag;
    for (int ii = 1; ii < n; ii++) {
        flag = 0;
        for (int j = 1; j <= m; j++) {
            int u = edges[j].from;
            int v = edges[j].to;
            int w = edges[j].weight;
            if (dist[u] < INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parents[v] = u;
                flag = 1;
            }
        }
        if (flag==0){
            cout << "YES\n";
            return;
        }
    }
    int counter = 0;
    for (int j = 1; j <= m; j++) {
        int u = edges[j].from;
        int v = edges[j].to;
        int w = edges[j].weight;
        if (dist[u] < INF && dist[u] + w < dist[v]) {
            for (int ii = 0; ii < n; ++ii) {
                v=parents[v];
            }
            u = v;
            while (u!=parents[v]){
                counter++;
                v=parents[v];
            }
        }
    }
    if (counter <= k){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}


int main() {
    int N, k;
    cin >> N >> k;
    for (int i = 0; i < N; ++i) {
        func(k);
    }
    return 0;
}