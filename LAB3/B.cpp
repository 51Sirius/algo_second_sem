#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

bool has_path(int a, int b, vector<int> *graph, vector<bool> &visited) {
    stack<int> st;
    st.push(a);
    visited[a] = true;
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (u == b) {
            return true;
        }
        for (auto v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                st.push(v);
            }
        }
    }
    return false;
}


int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> graph[n+1];
    vector<bool> visited(n+1, false);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < q; i++) {
        int u, v;
        char command;
        cin >> command >> u >> v;
        visited.assign(n+1, false);
        if(command == '?'){
            if (has_path(u, v, graph, visited)) {
                cout << "YES"<<endl;
            } else {
                cout << "NO"  << endl;
            }
        } else if(command=='-'){
            auto it = std::remove(graph[u].begin(), graph[u].end(), v);
            graph[u].erase(it, graph[u].end());
            auto it2 = std::remove(graph[v].begin(), graph[v].end(), u);
            graph[v].erase(it2, graph[v].end());
        }
    }
    return 0;
}