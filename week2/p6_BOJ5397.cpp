#include <iostream>
#include <list>
#include <string>

using namespace std;

// 키로거: 커서 오른쪽 문자의 iterator를 유지하면서 입력을 순서대로 처리한다.
// '<', '>'는 이동, '-'는 왼쪽 문자 삭제, 나머지는 커서 앞에 삽입한다.
// 테스트 케이스마다 입력 길이 L에 대해 시간 O(L), 공간 O(L).
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string input;
        cin >> input;

        list<char> password;
        auto cursor = password.end();

        for (char key : input) {
            if (key == '<') {
                if (cursor != password.begin()) {
                    --cursor;
                }
            } else if (key == '>') {
                if (cursor != password.end()) {
                    ++cursor;
                }
            } else if (key == '-') {
                if (cursor != password.begin()) {
                    --cursor;
                    cursor = password.erase(cursor);
                }
            } else {
                password.insert(cursor, key);
            }
        }

        for (char value : password) {
            cout << value;
        }
        cout << '\n';
    }

    return 0;
}
