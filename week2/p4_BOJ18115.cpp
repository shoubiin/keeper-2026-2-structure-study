#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using namespace std;

// 카드 놓기: 기술을 거꾸로 실행하며 1번 카드부터 손에 되돌려 놓는다.
// 기술 1은 맨 앞, 기술 2는 두 번째, 기술 3은 맨 뒤에 삽입한다.
// list의 앞쪽을 카드 더미의 위쪽으로 둔다. 시간 O(N), 공간 O(N).
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> skills(n);
    for (int i = 0; i < n; i++) {
        cin >> skills[i];
    }

    list<int> cards;
    int card = 1;

    for (int i = n - 1; i >= 0; i--) {
        if (skills[i] == 1) {
            cards.push_front(card);
        } else if (skills[i] == 2) {
            // 기술 2는 카드가 2장 이상일 때만 사용하므로 복구 시 맨 앞 카드가 있다.
            cards.insert(next(cards.begin()), card);
        } else {
            cards.push_back(card);
        }
        card++;
    }

    for (int number : cards) {
        cout << number << ' ';
    }
    cout << '\n';

    return 0;
}
