#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
  int answer = 0;
  int h = board.size(), w = board[0].size();

  vector<stack<int>> v(w+1);
  stack<int> basket;

  for(int i = h-1; i >= 0; i--){
    for(int j = 0; j < w; j++ ){
      if(board[i][j] != 0) v[j].push(board[i][j]);
    }
  }

  for(int m = 0; m < moves.size(); m++){
    int i = moves[m]; // 크레인이 인형을 꺼낼 칸 번호
    if(v[i-1].size() == 0) continue; // 칸에 인형이 없으면 지나감

    int target = v[i-1].top(); // target: 인형 번호
    v[i-1].pop();

    if(basket.size() > 0 && basket.top() == target) {
      basket.pop(); answer += 2;
    } else basket.push(target);
  }
  return answer;
}