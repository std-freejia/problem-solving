#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;

    sort(d.begin(), d.end());
    
    for(int i = 0; i < d.size(); i++) {
        if (budget < d[i]) break;
        budget -= d[i];
        answer++;
    }
    return answer;
}
