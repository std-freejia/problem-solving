#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char, int> charMap;

    for(int i = 0; i < s.length(); ++i) {
        char targetChar = s.at(i);

        if (charMap.find(targetChar) == charMap.end()) {
            charMap[targetChar] = i;
            answer.push_back(-1);
        } else {
            int idx = charMap[targetChar];
            charMap[targetChar] = i;
            answer.push_back(i - idx);
        }
    }
    return answer;
}
