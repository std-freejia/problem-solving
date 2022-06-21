#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N, M, answer, front, mid, back;
int blue[100001]; // 강의 길이 목록

bool b_search(int mid){ // mid 크기의 M장 블루레이에 모두 담기는지 확인.

  int sum_time = 0, cnt = 1; // sum_time 은 mid 이하여야 한다. 블루레이 개수 cnt.

  for(int i = N-1; i>=0; i--){

    if(blue[i] > mid){
      return false; // 1장에 1곡도 못들어가는 경우.
    }

    sum_time += blue[i];
    if(sum_time > mid){
      cnt++;
      sum_time = blue[i];
    }
  }
  return M >= cnt; // 블루레이 개수가 M이하라면 만족.
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    cin >> blue[i];
    back += blue[i];
  }
  front = 1;

  while(front <= back){

    mid = (front + back) / 2; // 블루레이의 크기

    if(b_search(mid)){
      answer = mid;
      back = mid-1;
    }else{
      front = mid+1;
    }
  }
  cout << answer;
  return 0;
}