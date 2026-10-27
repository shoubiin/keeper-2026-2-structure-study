#include <deque>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int commandCount;
    cin >> commandCount;
    deque<int> numbers;

    while (commandCount--) {
        string command;
        cin >> command;

        if (command == "push_front" || command == "push_back") {
            int value;
            cin >> value;
            if (command == "push_front") numbers.push_front(value);
            else numbers.push_back(value);
        } else if (command == "pop_front") {
            if (numbers.empty()) cout << -1 << '\n';
            else {
                cout << numbers.front() << '\n';
                numbers.pop_front();
            }
        } else if (command == "pop_back") {
            if (numbers.empty()) cout << -1 << '\n';
            else {
                cout << numbers.back() << '\n';
                numbers.pop_back();
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
