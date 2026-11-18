#include <cstdlib>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int operationCount;
    cin >> operationCount;
    priority_queue<pair<long long, long long>,
                   vector<pair<long long, long long>>,
                   greater<pair<long long, long long>>> absHeap;

    while (operationCount--) {
        long long value;
        cin >> value;
        if (value != 0) {
            absHeap.push({llabs(value), value});
        } else if (absHeap.empty()) {
            cout << 0 << '\n';
        } else {
            cout << absHeap.top().second << '\n';
            absHeap.pop();
        }
    }
    return 0;
}
