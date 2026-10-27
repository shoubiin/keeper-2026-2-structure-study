#include <deque>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCount;
    cin >> testCount;
    while (testCount--) {
        string commands, arrayText;
        int numberCount;
        cin >> commands >> numberCount >> arrayText;

        deque<int> numbers;
        int value = 0;
        for (char character : arrayText) {
            if (character >= '0' && character <= '9') {
                value = value * 10 + (character - '0');
            } else if (character == ',' || character == ']') {
                if (numberCount > 0) {
                    numbers.push_back(value);
                    value = 0;
                }
            }
        }

        bool reversed = false;
        bool error = false;
        for (char command : commands) {
            if (command == 'R') {
                reversed = !reversed;
            } else if (numbers.empty()) {
                error = true;
                break;
            } else if (reversed) {
                numbers.pop_back();
            } else {
                numbers.pop_front();
            }
        }

        if (error) {
            cout << "error\n";
            continue;
        }

        cout << '[';
        while (!numbers.empty()) {
            if (reversed) {
                cout << numbers.back();
                numbers.pop_back();
            } else {
                cout << numbers.front();
                numbers.pop_front();
            }
            if (!numbers.empty()) cout << ',';
        }
        cout << "]\n";
    }

    return 0;
}
