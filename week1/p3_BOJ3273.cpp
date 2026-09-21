#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int x;
    cin >> x;

    sort(a.begin(), a.end());

    int left = 0;
    int right = n - 1;
    int count = 0;

    while (left < right) {
        int sum = a[left] + a[right];

        if (sum == x) {
            count++;
            left++;
            right--;
        } else if (sum < x) {
            left++;
        }
        else {
            right--;
        }

        cout << count << '\n';
    }

/* 이렇게 하면 n이 최대 100,000이면 약 50억 쌍을 확인해야 해서
1초 안에 실행할 수 없게된다함

    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] + a[j] == 13) {
                count += 1;
            }
        }
    }

    cout << count;
*/  


}