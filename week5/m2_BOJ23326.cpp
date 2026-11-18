#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int areaCount, queryCount;
    cin >> areaCount >> queryCount;
    set<int> attractions;
    for (int area = 1; area <= areaCount; ++area) {
        int isAttraction;
        cin >> isAttraction;
        if (isAttraction) attractions.insert(area);
    }

    int currentArea = 1;
    while (queryCount--) {
        int queryType;
        cin >> queryType;
        if (queryType == 1) {
            int area;
            cin >> area;
            if (attractions.count(area)) attractions.erase(area);
            else attractions.insert(area);
        } else if (queryType == 2) {
            long long steps;
            cin >> steps;
            currentArea = (currentArea - 1 + steps) % areaCount + 1;
        } else {
            if (attractions.empty()) {
                cout << -1 << '\n';
                continue;
            }
            auto next = attractions.lower_bound(currentArea);
            if (next == attractions.end()) next = attractions.begin();
            cout << (*next - currentArea + areaCount) % areaCount << '\n';
        }
    }
    return 0;
}
