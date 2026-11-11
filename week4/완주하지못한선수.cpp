
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> m;

    // 1. 참가자 이름별 인원수 증가
    for (string name : participant) {
        m[name]++;
    }

    // 2. 완주한 사람의 인원수 감소
    for (string name : completion) {
        m[name]--;
    }

    // 3. 인원수가 남아 있는 사람 찾기
    for (auto p : m) {
        if (p.second > 0) {
            return p.first;
        }
    }

    return "";
}
