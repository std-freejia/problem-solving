#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> number_vector;
int answer_count;

void dfs(int count, int idx, int currentSum) {

    if (count == 3) {
        if (currentSum == 0) answer_count++;
        return; 
    }
    if (count > 3 ) {
        return; 
    }

    for (int i = idx; i < number_vector.size(); i++) {
        dfs(count + 1, i+1, currentSum + number_vector[i]);
    }
}
int solution(vector<int> number) {
    int answer = 0;
    sort(number.begin(), number.end());
    number_vector = number;

    dfs(0, 0, 0);
    return answer_count;
}

