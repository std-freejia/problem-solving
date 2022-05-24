#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int D1[1000001]; // 첫번째 집을 턴다
int D2[1000001]; // 첫번째 집 안털고, 마지막 집을 턴다.

int solution(vector<int> money) {
  int answer = 0;
  int msize = money.size();

  D1[0] = money[0]; // D1: 첫번째 집을 턴다.
  D1[1] = max(money[0], money[1]);

  D2[0] = 0;        // D2: 마지막 집을 턴다.
  D2[1] = money[1];

  for(int i = 2; i < msize-1 ; i++) { // 첫번째 집을 터니까 msize-2 까지 반복.
    D1[i] = max(D1[i-2] + money[i], D1[i-1]);
  }
  for(int i = 2; i < msize; i++) { // 마지막 집을 터니까 msize-1 까지 반복.
    D2[i] = max(D2[i-2] + money[i], D2[i-1]);
  }
  answer = max(D1[msize-2], D2[msize-1]);
  return answer;
}