#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    for(int end_idx = 9; end_idx < discount.size(); end_idx++) {
        int start_idx = end_idx - 9;

        vector<string> subset(discount.begin()+start_idx, discount.begin() + end_idx + 1);

        int size_of_want = want.size();
        bool result = true;

        for(int i = 0; i < size_of_want; i++) {
            int c = count(subset.begin(), subset.end(), want[i]);

            if (c != number[i]) {
                result = false;
                break;
            }
        }
        if (result) answer++;

    }
    return answer;
}

