#include <iostream>
#include <list>

using namespace std;

// 요세푸스 문제: 현재 사람을 1번째로 세어 K번째 사람을 삭제한다.
// 끝에 도착하면 begin()으로 돌아가 원형 연결 리스트처럼 사용한다.
// 시간 O(NK), 공간 O(N).
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    list<int> people;
    for (int i = 1; i <= n; i++) {
        people.push_back(i);
    }

    auto current = people.begin();
    cout << '<';

    while (!people.empty()) {
        // 원을 한 바퀴 도는 이동은 생략할 수 있다.
        int steps = (k - 1) % static_cast<int>(people.size());
        for (int i = 0; i < steps; i++) {
            ++current;
            if (current == people.end()) {
                current = people.begin();
            }
        }

        cout << *current;
        current = people.erase(current); // 삭제한 사람의 다음 사람을 반환한다.

        if (!people.empty()) {
            cout << ", ";
            if (current == people.end()) {
                current = people.begin();
            }
        }
    }

    cout << ">\n";
    return 0;
}
