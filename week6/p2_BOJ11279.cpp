#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int operationCount;
    cin >> operationCount;
    priority_queue<int> maxHeap;

    while (operationCount--) {
        int value;
        cin >> value;
        if (value != 0) {
            maxHeap.push(value);
        } else if (maxHeap.empty()) {
            cout << 0 << '\n';
        } else {
            cout << maxHeap.top() << '\n';
            maxHeap.pop();
        }
    }
    return 0;
}
