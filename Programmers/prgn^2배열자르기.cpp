#include <string>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

vector<int> answer;
vector<int> v;
vector<int> solution(int n, long long left, long long right) {

  for(ll i = left; i <= right; i++){
    answer.push_back(1+ max(i / n, i % n));
  }
  return answer;
}