#include <iostream>
#include <list>
#include <string>

using namespace std;

// 에디터: cursor는 커서 바로 오른쪽 문자를 가리킨다. end()이면 맨 뒤이다.
// 연결 리스트에서는 커서 이동, 삽입, 삭제를 각각 O(1)에 처리한다.
// 초기 문자열 길이 N, 명령 수 M에 대해 시간 O(N + M), 공간 O(N + M).
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string initial;
    cin >> initial;

    list<char> text(initial.begin(), initial.end());
    auto cursor = text.end();

    int m;
    cin >> m;

    while (m--) {
        char command;
        cin >> command;

        if (command == 'L') {
            if (cursor != text.begin()) {
                --cursor;
            }
        } else if (command == 'D') {
            if (cursor != text.end()) {
                ++cursor;
            }
        } else if (command == 'B') {
            if (cursor != text.begin()) {
                --cursor;
                cursor = text.erase(cursor);
            }
        } else if (command == 'P') {
            char value;
            cin >> value;
            // 현재 iterator 앞에 삽입하면 커서는 새 문자의 오른쪽에 유지된다.
            text.insert(cursor, value);
        }
    }

    for (char value : text) {
        cout << value;
    }
    cout << '\n';

    return 0;
}
