#include <iostream>
#include <list>

using namespace std;

// 줄 세우기: 줄의 끝에서 뽑은 수만큼 앞으로 이동한 위치에 삽입한다.
// list는 이중 연결 리스트이므로 원소를 밀지 않고 삽입할 수 있다.
// 시간 O(N^2), 공간 O(N). 삽입 위치까지 이동하는 데 O(N)이 걸린다.
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    list<int> students;

    for (int student = 1; student <= n; student++) {
        int number;
        cin >> number;

        auto pos = students.end();
        for (int i = 0; i < number; i++) {
            --pos;
        }
        students.insert(pos, student);
    }

    for (int student : students) {
        cout << student << ' ';
    }
    cout << '\n';

    return 0;
}
