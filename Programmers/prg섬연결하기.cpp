#include <bits/stdc++.h>
using namespace std;

// 크루스칼 알고리즘
int get_parent(vector<int> &parent, int a){
  if(parent[a] == a) return a; // 부모가 자신이라면, 자신을 리턴
  return parent[a] = get_parent(parent, parent[a]); // 최상위 부모 찾기
}

void union_parent(vector<int> &parent, int a, int b){
  a = get_parent(parent, a);
  b = get_parent(parent, b);
  // 작은 노드쪽의 부모로 병합
  (a < b) ? parent[b] = a : parent[a] = b;
}

bool find(vector<int> &v, int a, int b){
  a = get_parent(v, a);
  b = get_parent(v, b);
  return a == b; // 사이클 방지
}

bool cmp(vector<int> &a, vector<int> &b){
  return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
  int answer = 0, maxNum = 0;
  vector<pair<int,int>> co;

  // 비용 오름차순 정렬
  sort(costs.begin(), costs.end(), cmp);
  for(auto c : costs) if(maxNum < c[1]) maxNum = c[1];

  // i번째 노드의 부모 노드를 저장하는 parent 벡터
  vector<int> parent;
  for(int i = 0; i <= maxNum; i++ ) parent.push_back(i);

  for(auto c : costs){
    // 두 개의 부모 노드가 다르다면, 사이클 X
    if(!find(parent, c[0], c[1])){
      answer += c[2]; // 결과에 가중치 추가
      union_parent(parent, c[0], c[1]);
    }
  }
  return answer;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n = 4;
  vector<vector<int>> costs{{0,1,1}, {0,2,2}, {1,2,5}, {1,3,1}, {2,3,8}};
  cout << solution(n, costs);

  return 0;
}
