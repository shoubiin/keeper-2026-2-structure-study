#include <iostream>
#include <string>

using namespace std;

// 철도 공사: 역 번호를 노드 인덱스로 쓰는 원형 이중 연결 리스트이다.
// prevStation[i], nextStation[i]는 i번 역의 이전/다음 역 번호이다.
// 역을 찾는 데 순회가 필요 없고, 삽입/삭제는 양쪽 연결만 바꾸면 된다.
// 명령 처리 O(N + M), 배열 초기화까지 시간/공간 O(N + M + U)/O(U).
// U = 역 번호의 최댓값 1,000,000.
const int MAX_STATION = 1000000;
int prevStation[MAX_STATION + 1];
int nextStation[MAX_STATION + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int first;
    cin >> first;
    int last = first;

    for (int i = 1; i < n; i++) {
        int station;
        cin >> station;
        nextStation[last] = station;
        prevStation[station] = last;
        last = station;
    }

    // 역이 하나뿐인 경우에도 자신을 양쪽 이웃으로 연결한다.
    nextStation[last] = first;
    prevStation[first] = last;

    while (m--) {
        string command;
        int i;
        cin >> command >> i;

        if (command == "BN") {
            int j;
            cin >> j;
            int right = nextStation[i];
            cout << right << '\n';

            nextStation[i] = j;
            prevStation[j] = i;
            nextStation[j] = right;
            prevStation[right] = j;
        } else if (command == "BP") {
            int j;
            cin >> j;
            int left = prevStation[i];
            cout << left << '\n';

            nextStation[left] = j;
            prevStation[j] = left;
            nextStation[j] = i;
            prevStation[i] = j;
        } else if (command == "CN") {
            int removed = nextStation[i];
            int right = nextStation[removed];
            cout << removed << '\n';

            nextStation[i] = right;
            prevStation[right] = i;
        } else if (command == "CP") {
            int removed = prevStation[i];
            int left = prevStation[removed];
            cout << removed << '\n';

            nextStation[left] = i;
            prevStation[i] = left;
        }
    }

    return 0;
}
