
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> m;

    // 1. 의상 종류별 개수 세기
    for (auto cloth : clothes) {
        m[cloth[1]]++;
    }

    // 2. 종류별 (개수 + 1)을 곱하기
    int answer = 1;

    for (auto p : m) {
        answer *= (p.second + 1);
    }

    // 3. 아무것도 입지 않는 경우 제외
    return answer - 1;
}
