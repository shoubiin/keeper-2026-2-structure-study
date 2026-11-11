#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int nodeCount;
    cin >> nodeCount;
    vector<vector<int>> adj(nodeCount + 1);
    for (int i = 0; i < nodeCount - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> parent(nodeCount + 1, 0);
    queue<int> q;
    parent[1] = -1;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (parent[v] != 0) continue;
            parent[v] = u;
            q.push(v);
        }
    }

    for (int node = 2; node <= nodeCount; ++node) {
        cout << parent[node] << '\n';
    }
    return 0;
}
