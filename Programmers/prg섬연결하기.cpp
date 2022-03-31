#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
  return a[2] < b[2];
}
int get_parent(vector<int> &parent, int x){
  // 부모노드가 자신이라면 자신을 리턴
  if(parent[x] == x) return x;
  // 부모노드가 자신이 아니라면, 최상위 부모 찾기
  return parent[x] = get_parent(parent, parent[x]);
}

void union_parent(vector<int> &parent, int a, int b){
  a = get_parent(parent, a);
  b = get_parent(parent, b);
  // 작은 노드쪽의 부모로 병합
  a < b ? parent[b] = a : parent[a] = b;
}
bool find(vector<int> &parent, int a, int b){
  a = get_parent(parent, a);
  b = get_parent(parent, b);
  return a == b; // 비교 내용을 리턴, 사이클 방지용
}
// 크루스칼 알고리즘 : 비용이 적은 순으로 costs 정렬
int solution(int n, vector<vector<int>> costs) {
  int answer = 0, maxNum = 0;

  sort(costs.begin(), costs.end(), cmp);
  for(auto c : costs) if(maxNum < c[1]) maxNum = c[1];

  vector<int> parent; // i번째 노드의 부모노드를 저장하는 parent 벡터
  for(int i = 0; i <= maxNum; i++) parent.push_back(i);

  for(auto c : costs){
    // 두 개의 부모 노드가 다르다면 (사이클 없다면)
    if(!find(parent, c[0], c[1])){
      answer += c[2]; // 결과에 가중치 추가
      union_parent(parent, c[0], c[1]); // 부모노드 병합
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
