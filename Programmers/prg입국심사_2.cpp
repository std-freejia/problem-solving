#include <bits/stdc++.h>
using namespace std;

long long solution(int n, vector<int> times) {

  int size_of_times = times.size();
  sort(times.begin(), times.end());

  long long min_time = 1L; // 가장 짧은 시간
  long long max_time = (long long)times[size_of_times-1] * n; // 가장 오래걸리는 시간
  long long mid_time = (min_time + max_time) / 2; // 중앙값
  long long answer = max_time;

  while(min_time <= max_time){

    mid_time = (min_time + max_time) / 2;
    long long man_cnt = 0;
    for(auto t : times) { // mid_time 동안 처리할 수 있는 사람 수를 센다.
      man_cnt += mid_time / t;
    }

    if(n <= man_cnt){
      answer = min(answer, mid_time);
      max_time = mid_time - 1;
    }
    else {
      min_time = mid_time + 1; // 시간이 부족
    }
  }
  return answer;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n = 6;
  vector<int> times = {7, 10};
  cout << solution(n, times);

  return 0;
}