#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long answer, min_time, max_time, mid_time, man_cnt;

long long solution(int n, vector<int> times) {
  int v_len = times.size();
  min_time = 1;
  max_time = (long long) *max_element(times.begin(), times.end()) * n; // 제일느린 사람이 n개 전부 심사

  while(min_time <= max_time){
    mid_time = (min_time + max_time) / 2;
    man_cnt = 0; // 모든 심사원들이 mid_time 동안 심사할 수 있는 사람 수.

    for(int i = 0; i < v_len; i++) man_cnt += (mid_time / times[i]);
    if(n <= man_cnt){
      max_time = mid_time - 1;
      answer = mid_time;
    }
    else{
      min_time = mid_time + 1;
    }
  }
  return answer;
}
