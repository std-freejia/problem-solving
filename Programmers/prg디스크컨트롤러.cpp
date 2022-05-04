#include <bits/stdc++.h>
using namespace std;

struct cmp
{
public:
  bool operator()(vector<int> &a, vector<int> &b){
    return a[1] > b[1]; // 소요시간 기준 오름차순
  }
};

int solution(vector<vector<int>> jobs) {
  int jobs_idx = 0;

  sort(jobs.begin(), jobs.end()); // 작업들은 요청시각 기준 오름차순
  priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

  int end_time = 0, sum = 0;

  while(!pq.empty() || jobs_idx < jobs.size()){

    // 지금 처리중인 작업이 종료되기 전에, 요청이 들어온 작업이 발생하면?
    if(jobs_idx < jobs.size() && jobs[jobs_idx][0] <= end_time){
      pq.push(jobs[jobs_idx++]);
      continue;
    }

    if(!pq.empty()){
      end_time += pq.top()[1]; // 소요시간
      sum += (end_time - pq.top()[0]); // 요청 시각 ~ 종료 시각
      pq.pop();
    }else{
      end_time = jobs[jobs_idx][0]; // 다음 작업의 요청 시각으로 갱신
    }
  }

  return (sum / jobs.size());
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<vector<int>> jobs{{0,3}, {1,9}, {2,6}};
  cout << solution(jobs);

  return 0;
}