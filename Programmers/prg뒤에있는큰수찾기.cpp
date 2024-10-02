#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    int size = numbers.size();
    vector<int> answer(size, -1);
    stack<int> s;
    
    for(int i = size - 1; i >= 0; --i) {
        while(true) {
            if(s.empty()) {
                break;
            }
            if (numbers[i] < s.top()) {
                answer[i] = s.top();
                break;
            }
            s.pop();
        }
        s.push(numbers[i]);
    }
    return answer;
}
