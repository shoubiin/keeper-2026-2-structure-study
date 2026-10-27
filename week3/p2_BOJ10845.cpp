#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int commandCount;
    cin >> commandCount;
    queue<int> numbers;

    while (commandCount--) {
        string command;
        cin >> command;

        if (command == "push") {
            int value;
            cin >> value;
            numbers.push(value);
        } else if (command == "pop") {
            if (numbers.empty()) {
                cout << -1 << '\n';
            } else {
                cout << numbers.front() << '\n';
                numbers.pop();
            }
        } else if (command == "size") {
            cout << numbers.size() << '\n';
        } else if (command == "empty") {
            cout << numbers.empty() << '\n';
        } else if (command == "front") {
            cout << (numbers.empty() ? -1 : numbers.front()) << '\n';
        } else if (command == "back") {
            cout << (numbers.empty() ? -1 : numbers.back()) << '\n';
        }
    }

    return 0;
}
