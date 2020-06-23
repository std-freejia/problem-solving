#include <stdio.h>
#include <algorithm>
#include <stack>
#include <vector> 
using namespace std;

// 55. 기차운행  train_stack  (어려웠지만 중요한문제)

/*

P (push) 기차를 교차로에 넣는다. 
O (out) 최상단 기차를 B도시로 보낸다. 
				
* 입력설명 
첫 번째 줄에 자연수 N(3<=N<=30)가 주어진다.
두 번째 줄에 A도시에서 출발하는 기차번호순이 차례대로 입력된다.

* 출력설명
교차로 작업을 순서대로 P와 O로 출력한다.

*/

int main(int argc, char** argv){
	
	//freopen("input.txt", "rt", stdin);
	
	stack<int> s; 
	int i, j=1; 
	int n, m = 0;
	
	// P, O 저장할 벡터
	vector<char> str;
	 
	scanf("%d", &n);
	
	for(i=1; i<=n; i++){
		scanf("%d", &m);
		
		s.push(m);
		str.push_back('P'); 
		
		while(1){
			
			if(s.empty()) break;
			
			if(j == s.top()){
				s.pop();
				j++;
				str.push_back('O'); 

			}else{
				break;
			}
		}
		
	}
	
	if(!s.empty()){
		printf("impossible\n");
	}else{ 
		for(i=0; i<str.size(); i++){
			printf("%c", str[i]);
		}
	}
	
	return 0;
} 
