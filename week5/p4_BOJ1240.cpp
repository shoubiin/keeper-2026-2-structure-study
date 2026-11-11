#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int nodeCount, queryCount;
    cin >> nodeCount >> queryCount;
    vector<vector<pair<int, int>>> adj(nodeCount + 1);
    for (int i = 0; i < nodeCount - 1; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    while (queryCount--) {
        int start, target;
        cin >> start >> target;
        vector<int> distance(nodeCount + 1, -1);
        queue<int> q;
        distance[start] = 0;
        q.push(start);

        while (!q.empty() && distance[target] == -1) {
            int u = q.front();
            q.pop();
            for (const auto& edge : adj[u]) {
                int v = edge.first;
                if (distance[v] != -1) continue;
                distance[v] = distance[u] + edge.second;
                q.push(v);
            }
        }
        cout << distance[target] << '\n';
    }
    return 0;
}
