#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;

    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end()); //sort 함수를 기억하자..

    for (int i = 0; i < n; i++) {
        cout << a[i] << '\n';
    }

    return 0;

}