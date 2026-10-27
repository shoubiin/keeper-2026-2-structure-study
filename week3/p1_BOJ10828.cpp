#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int commandCount;
    cin >> commandCount;
    stack<int> numbers;

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
                cout << numbers.top() << '\n';
                numbers.pop();
            }
        } else if (command == "size") {
            cout << numbers.size() << '\n';
        } else if (command == "empty") {
            cout << numbers.empty() << '\n';
        } else if (command == "top") {
            cout << (numbers.empty() ? -1 : numbers.top()) << '\n';
        }
    }

    return 0;
}
