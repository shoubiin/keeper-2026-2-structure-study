#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    a.insert(a.end(), b.begin(), b.end()); //a의 end에 b의 전체를 insert

    sort(a.begin(), a.end());  

    for (int x : a) { 
        cout << x << ' ';
    }
}