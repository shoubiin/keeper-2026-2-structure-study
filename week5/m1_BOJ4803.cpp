#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int findRoot(vector<int>& parent, int node) {
    if (parent[node] == node) return node;
    return parent[node] = findRoot(parent, parent[node]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int nodeCount, edgeCount;
    int caseNumber = 1;
    while (cin >> nodeCount >> edgeCount && (nodeCount != 0 || edgeCount != 0)) {
        vector<int> parent(nodeCount + 1);
        iota(parent.begin(), parent.end(), 0);
        vector<pair<int, int>> edges;
        edges.reserve(edgeCount);

        for (int i = 0; i < edgeCount; ++i) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
            parent[findRoot(parent, u)] = findRoot(parent, v);
        }

        vector<int> vertices(nodeCount + 1, 0);
        vector<int> componentEdges(nodeCount + 1, 0);
        for (int node = 1; node <= nodeCount; ++node) {
            ++vertices[findRoot(parent, node)];
        }
        for (const auto& edge : edges) {
            ++componentEdges[findRoot(parent, edge.first)];
        }

        int treeCount = 0;
        for (int node = 1; node <= nodeCount; ++node) {
            if (vertices[node] > 0 && componentEdges[node] == vertices[node] - 1) {
                ++treeCount;
            }
        }

        cout << "Case " << caseNumber++ << ": ";
        if (treeCount == 0) cout << "No trees.\n";
        else if (treeCount == 1) cout << "There is one tree.\n";
        else cout << "A forest of " << treeCount << " trees.\n";
    }
    return 0;
}
