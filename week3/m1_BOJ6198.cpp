#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int buildingCount;
    cin >> buildingCount;
    stack<int> visibleBuildings;
    long long answer = 0;

    for (int i = 0; i < buildingCount; ++i) {
        int height;
        cin >> height;

        while (!visibleBuildings.empty() && visibleBuildings.top() <= height) {
            visibleBuildings.pop();
        }
        answer += visibleBuildings.size();
        visibleBuildings.push(height);
    }

    cout << answer << '\n';
    return 0;
}
