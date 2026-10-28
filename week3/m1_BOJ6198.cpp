#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int count;
    cin >> count;
    stack<int> visibleBuildings;
    long long answer = 0;

    for (int i = 0; i < count; ++i) {
        int height;
        cin >> height;

        //현재 건물보다 작거나 같은경우는 제거하면됨
        while (!visibleBuildings.empty() && visibleBuildings.top() <= height) {
            visibleBuildings.pop();
        }
        answer += visibleBuildings.size(); //현재 남은 건물을 더하면 됨
        visibleBuildings.push(height); //높이를 다시 보이는 건물에 push
    }

    cout << answer << '\n';
    return 0;
}
