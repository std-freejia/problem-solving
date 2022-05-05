#include <string>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<>> min_pq;
priority_queue<int, vector<int>, less<>> max_pq;
int pq_size; // 큐의 사이즈 관리

vector<int> solution(vector<string> op) {
  vector<int> answer = {0, 0};

  for(auto s : op){
    string order = s.substr(0, 1); // 명령 문자 I 또는 D

    int num = stoi(s.substr(2, s.size())); // 숫자부분

    if(order == "I") {
      min_pq.push(num);
      max_pq.push(num);
      pq_size++;
    }
    else if(pq_size > 0 && order == "D"){

      (num == -1) ? min_pq.pop() : max_pq.pop();
      pq_size--;

      if(pq_size == 0){
        while(!min_pq.empty()) min_pq.pop();
        while(!max_pq.empty()) max_pq.pop();
      }
    }
  }

  if(!min_pq.empty() && !max_pq.empty()) answer = {max_pq.top(), min_pq.top()};
  return answer;
}