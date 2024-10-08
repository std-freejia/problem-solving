#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm> 

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int currentSum = 0;
    unordered_map<int, int> countMap;
    vector<pair<int, int>> countList;

    for (int num: tangerine) {
        countMap[num]++;
    }

    for (const auto& entry : countMap) {
        countList.push_back({entry.first, entry.second});
    }

    std::sort(countList.begin(), countList.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second > b.second; // 등장 횟수가 큰 순서대로 정렬
    });

    for (const auto& pair : countList) {
        currentSum += pair.second;
        answer++;
        if (currentSum >= k) {
            break;
        }
    }
    return answer;
}
