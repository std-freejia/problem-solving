#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    vector<int> answer;

    for(auto &a: arr) {

        int target_idx = find(delete_list.begin(), delete_list.end(), a) - delete_list.begin();
        if ( target_idx == delete_list.size()) {
            answer.push_back(a);
        }
    }
    return answer;
}
