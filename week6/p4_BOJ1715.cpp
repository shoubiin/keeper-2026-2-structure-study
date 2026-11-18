#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int pileCount;
    cin >> pileCount;
    priority_queue<long long, vector<long long>, greater<long long>> piles;
    for (int i = 0; i < pileCount; ++i) {
        long long size;
        cin >> size;
        piles.push(size);
    }

    long long totalComparisons = 0;
    while (piles.size() > 1) {
        long long first = piles.top();
        piles.pop();
        long long second = piles.top();
        piles.pop();
        long long merged = first + second;
        totalComparisons += merged;
        piles.push(merged);
    }

    cout << totalComparisons << '\n';
    return 0;
}
