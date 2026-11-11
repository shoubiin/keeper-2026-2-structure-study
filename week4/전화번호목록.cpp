
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set<string> s;

    // 모든 전화번호를 저장
    for (string phone : phone_book) {
        s.insert(phone);
    }

    // 각 전화번호의 접두어 확인
    for (string phone : phone_book) {
        for (int i = 1; i < phone.size(); i++) {
            string prefix = phone.substr(0, i);

            if (s.find(prefix) != s.end()) {
                return false;
            }
        }
    }

    return true;
}
