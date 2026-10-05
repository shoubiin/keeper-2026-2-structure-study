#include <iostream>
#include <list>
#include <utility>

using namespace std;

// 풍선 터뜨리기: (풍선 번호, 종이의 수)를 이중 연결 리스트에 저장한다.
// 삭제 후 iterator는 오른쪽 풍선을 가리키므로 양수일 때는 한 칸 덜 이동한다.
// 음수일 때는 삭제 후 위치에서 왼쪽으로 절댓값만큼 이동한다.
// 남은 풍선 수로 이동 횟수를 줄이면 시간 O(N^2), 공간 O(N).
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    list<pair<int, int>> balloons;
    for (int i = 1; i <= n; i++) {
        int number;
        cin >> number;
        balloons.push_back({i, number});
    }

    auto current = balloons.begin();

    while (!balloons.empty()) {
        cout << current->first << ' ';
        int move = current->second;
        current = balloons.erase(current);

        if (balloons.empty()) {
            break;
        }
        if (current == balloons.end()) {
            current = balloons.begin();
        }

        int remaining = static_cast<int>(balloons.size());
        if (move > 0) {
            int steps = (move - 1) % remaining;
            for (int i = 0; i < steps; i++) {
                ++current;
                if (current == balloons.end()) {
                    current = balloons.begin();
                }
            }
        } else {
            int steps = (-move) % remaining;
            for (int i = 0; i < steps; i++) {
                if (current == balloons.begin()) {
                    current = balloons.end();
                }
                --current;
            }
        }
    }

    cout << '\n';
    return 0;
}
