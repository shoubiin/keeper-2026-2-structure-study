#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for  (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> freq(100001, 0);
    int left = 0;
    int ans = 0;

    for (int right = 0; right < n; right++) {
        freq[a[right]]++;
        
        //k보다 freq가 크면 ? freq를 하나 줄이고? left를 올리는것
        while (freq[a[right]] > k) {
            freq[a[left]]--;
            left++;
        }

        ans = max(ans, right - left + 1);
    }
    cout << ans << '\n';

    return 0;
}