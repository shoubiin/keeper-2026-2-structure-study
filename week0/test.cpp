#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Programmers-style function: sort numbers and remove duplicates.
vector<int> solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end());
    numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());
    return numbers;
}

// Local test runner. Submit only the required solution function on Programmers.
int main() {
    int failures = 0;
    auto check = [&failures](bool passed, const string& name) {
        cout << (passed ? "[PASS] " : "[FAIL] ") << name << '\n';
        if (!passed) ++failures;
    };

    check(solution({3, 1, 2, 3, 2}) == vector<int>({1, 2, 3}),
          "vector + sort + unique");
    check(solution({}).empty(), "empty input");
    check(solution({-1, 0, -1, 5}) == vector<int>({-1, 0, 5}),
          "negative numbers");

    stack<int> st;
    st.push(10);
    st.push(20);
    check(st.top() == 20, "stack: last in, first out");
    st.pop();
    check(st.top() == 10 && st.size() == 1, "stack pop");

    queue<int> q;
    q.push(10);
    q.push(20);
    check(q.front() == 10, "queue: first in, first out");
    q.pop();
    check(q.front() == 20 && q.size() == 1, "queue pop");

    priority_queue<int> pq;
    for (int value : {3, 9, 1}) pq.push(value);
    check(pq.top() == 9, "priority_queue: largest first");
    pq.pop();
    check(pq.top() == 3, "priority_queue pop");

    unordered_map<string, int> counts;
    for (const string& word : vector<string>{"cpp", "study", "cpp"}) {
        ++counts[word];
    }
    check(counts.at("cpp") == 2 && counts.at("study") == 1,
          "unordered_map: frequency count");

    cout << '\n' << (failures == 0 ? "All tests passed!" : "Some tests failed.")
         << '\n';
    return failures == 0 ? 0 : 1;
}
