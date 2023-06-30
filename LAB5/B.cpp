#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    long long u, v, time;
};

long long find_root(vector<long long> &roots, long long u) {
    if (roots[u] == u) {
        return u;
    }
    roots[u] = find_root(roots, roots[u]);
    return roots[u];
}

void merge_trees(vector<long long> &roots, vector<long long> &height, long long u, long long v) {
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

void init_dsu(vector<long long> &roots, vector<long long> &height, long long n) {
    for (long long i = 1; i <= n; i++) {
        roots[i] = i;
        height[i] = i;
    }
}

void kruskal(long long n, vector<Edge> &edges, vector<Edge> &mst, long long &count) {
    vector<long long> roots(n + 1);
    vector<long long> height(n + 1);
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
    long long n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (long long i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].time;
    }
    vector<Edge> mst;
    long long count = 0;
    kruskal(n, edges, mst, count);
    cout << count;
    return 0;
}