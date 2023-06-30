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

int kruskal(int n, vector<Edge> &edges, vector<Edge> &mst, int &count, int m) {
    vector<int> roots(n + 1);
    vector<int> height(n + 1);
    init_dsu(roots, height, n);
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) -> bool {
        return a.time < b.time;
    });
    int flag = 0;
    bool first = true;
    for (int i = 0; i < m; i++) {
        if (find_root(roots, edges[i].u) != find_root(roots, edges[i].v)) {
            mst.push_back(edges[i]);
            merge_trees(roots, height, edges[i].u, edges[i].v);
            count += edges[i].time;
        } else if (first) {
            first = false;
            flag = i;
        }
    }
    return flag;
}

void kruskal2(int n, vector<Edge> &edges, vector<Edge> &mst, int &count, int m, int ind) {
    vector<int> roots(n + 1);
    vector<int> height(n + 1);
    init_dsu(roots, height, n);
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) -> bool {
        return a.time < b.time;
    });
    for (int i = 0; i < m; i++) {
        if (find_root(roots, edges[i].u) != find_root(roots, edges[i].v) and i != ind-1) {
            mst.push_back(edges[i]);
            merge_trees(roots, height, edges[i].u, edges[i].v);
            count += edges[i].time;
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
    vector<Edge> mst2;
    int count = 0;
    int ind = kruskal(n, edges, mst, count, m);
    cout << count << " ";
    count = 0;
    kruskal2(n, edges, mst2, count, m, ind);
    cout << count;
    return 0;
}