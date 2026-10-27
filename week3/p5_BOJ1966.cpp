#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCount;
    cin >> testCount;
    while (testCount--) {
        int documentCount, targetIndex;
        cin >> documentCount >> targetIndex;

        queue<pair<int, int>> documents;
        priority_queue<int> priorities;
        for (int i = 0; i < documentCount; ++i) {
            int priority;
            cin >> priority;
            documents.push({i, priority});
            priorities.push(priority);
        }

        int printedCount = 0;
        while (!documents.empty()) {
            auto document = documents.front();
            documents.pop();
            if (document.second != priorities.top()) {
                documents.push(document);
                continue;
            }

            priorities.pop();
            ++printedCount;
            if (document.first == targetIndex) {
                cout << printedCount << '\n';
                break;
            }
        }
    }

    return 0;
}
