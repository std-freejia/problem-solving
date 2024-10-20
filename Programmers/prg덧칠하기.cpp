#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 1;
    int start_idx = section[0];
    int section_length = section.size();

    for (int i = 0; i < section_length; i++) {
        // 현재인덱스가 롤러를 더한것보다 작으면, 지나간다. 
        if (section[i] < start_idx + m) continue;
        else { // 칠했음
            start_idx = section[i];
            answer++;
        }

    }
    return answer;
}
