#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, int> total;
    unordered_map<string, vector<pair<int, int>>> songs;

    // 1. 장르별 재생 횟수와 노래 저장
    for (int i = 0; i < genres.size(); i++) {
        total[genres[i]] += plays[i];
        songs[genres[i]].push_back({plays[i], i});
    }

    // 2. 장르 목록 만들기
    vector<pair<int, string>> genreList;

    for (auto p : total) {
        genreList.push_back({p.second, p.first});
    }

    // 3. 장르를 총 재생 횟수 내림차순 정렬
    sort(genreList.begin(), genreList.end(), greater<>());

    vector<int> answer;

    // 4. 재생 횟수가 높은 장르부터 처리
    for (auto g : genreList) {
        string genre = g.second;

        // 각 장르의 노래 정렬
        sort(songs[genre].begin(), songs[genre].end(),
             [](pair<int, int> a, pair<int, int> b) {
                 if (a.first == b.first) {
                     return a.second < b.second;
                 }
                 return a.first > b.first;
             });

        // 장르당 최대 2곡 선택
        int count = min(2, (int)songs[genre].size());

        for (int i = 0; i < count; i++) {
            answer.push_back(songs[genre][i].second);
        }
    }

    return answer;
}
