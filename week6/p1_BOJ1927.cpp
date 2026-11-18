#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int operationCount;
    cin >> operationCount;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    while (operationCount--) {
        int value;
        cin >> value;
        if (value != 0) {
            minHeap.push(value);
        } else if (minHeap.empty()) {
            cout << 0 << '\n';
        } else {
            cout << minHeap.top() << '\n';
            minHeap.pop();
        }
    }
    return 0;
}
