#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string arrangement;
    cin >> arrangement;
    stack<char> rods;
    int pieces = 0;

    for (size_t i = 0; i < arrangement.size(); ++i) {
        if (arrangement[i] == '(') {
            rods.push('(');
        } else {
            rods.pop();
            if (arrangement[i - 1] == '(') {
                pieces += static_cast<int>(rods.size()); // 레이저가 열린 막대기를 모두 자른다.
            } else {
                ++pieces; // 막대기 끝의 마지막 조각
            }
        }
    }

    cout << pieces << '\n';
    return 0;
}
