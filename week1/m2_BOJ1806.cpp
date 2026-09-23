#include <iostream>
using namespace std;

const int MAX = 100000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int s;
    cin >> n >> s;

    int arr[MAX];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    int end = 0;
    int minLength = n + 1;

    for (int start = 0; start < n; start++) {
        while (sum < s && end < n) {
            sum += arr[end];
            end++;
        }

        if (sum >= s) {
            minLength = min(minLength, end - start);
        }

        sum -= arr[start];
    }

    if (minLength == n + 1) {
        cout << 0 << '\n';
    } else {
        cout << minLength << '\n';
    }

    return 0;
}