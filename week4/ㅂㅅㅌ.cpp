#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, int> total;
    unordered_map<string, vector<pair<int, int>>> songs;

    for (int i = 0; i< genres.size(); i++) {
        total[genres[i]] += plays[i];
        songs[genres[i]].push_back({plays[i], i});
    }

    vector<pair<int, string>> genreList;

    for (auto p : total) {
        genreList.push_back({p.second, p.first});
    }

    sort(genreList.begin(), genreList.end(), greater<>());

    vector<int> answer;

    for (auto g : genreList) {
        string genre = g.second;

        sort(songs[genre].begin(), songs[genre].end(), 
            [](pair<int, int> a, pair<int, int> b) {
                if (a.first == b.first) {
                    return a.second < b.second;
                }
                return a.first > b.first;
            });
        
        int count = min(2, (int)songs[genre].size());

        for (int i = 0; i < count; i++) {
            answer.push_back(songs[genre][i].second);
        }
    }
    
    return answer;
}