#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> s;

    for (int num : nums) {
        s.insert(num);
    }

    int maxPick = nums.size() / 2;
    int kinds = s.size();

    return min(maxPick, kinds);
}