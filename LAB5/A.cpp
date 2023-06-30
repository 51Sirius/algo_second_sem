#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, time;
};

int find_root(vector<int> &roots, int u) {
    if (roots[u] == u) {
        return u;
    }
    roots[u] = find_root(roots, roots[u]);
    return roots[u];
}

void merge_trees(vector<int> &roots, vector<int> &height, int u, int v) {
    u = find_root(roots, u);
    v = find_root(roots, v);
    if (height[u] < height[v]) {
        swap(u, v);
    }
    roots[v] = u;
    if (height[u] == height[v]) {
        height[u]++;
    }
}

void init_dsu(vector<int> &roots, vector<int> &height, int n) {
    for (int i = 1; i <= n; i++) {
        roots[i] = i;
        height[i] = i;
    }
}

void kruskal(int n, vector<Edge> &edges, vector<Edge> &mst, int &count) {
    vector<int> roots(n + 1);
    vector<int> height(n + 1);
    init_dsu(roots, height, n);
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) -> bool {
        return a.time < b.time;
    });
    for (auto &e: edges) {
        if (find_root(roots, e.u) != find_root(roots, e.v)) {
            mst.push_back(e);
            merge_trees(roots, height, e.u, e.v);
            count += e.time;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].time;
    }
    vector<Edge> mst;
    int count = 0;
    kruskal(n, edges, mst, count);
    cout << count;
    return 0;
}