#include <stdio.h> 
#include <vector> 
#include <algorithm>
using namespace std;

// 25. 석차 구하기   ranking

/*
N명의 학생의 수학점수가 입력되면 각 학생의 석차를 입력된 순서대로 출력하는 프로그램을 작성하세요.

첫 줄에 N(1<=N<=100)이 입력되고, 두 번째 줄에 수학점수를 의미하는 N개의 정수가 입력된다. 
같은 점수가 입력될 경우 높은 석차로 동일 처리한다. 
즉 가장 높은 점수가 92점인데 92점이 3명 존재하면 1등이 3명이고 그 다음 학생은 4등이 된다. 
점수는 100점 만점이다.


input.txt
5
90 85 92 95 90

*/


int main(int argc, char** argv) {

	int total=0, i=0, j=0, temp=0, a=0;
	
	//freopen("input.txt", "rt", stdin);	

	scanf("%d", &total);
	
	vector<int> num(total);
	
	vector<int> rank(total, 1);
	
	for(i=0; i<total; i++){ // 점수 넣기  
		scanf("%d", &num[i]);
	}
	
	for(i=0; i<total; i++){
		
		for(j=0; j<total; j++){
			if(num[i] < num[j]){
				rank[i]++;
			}
		}

	}
	
	for(i=0; i<total; i++){ // 점수 넣기  
		printf("%d ", rank[i]);
	}
	
	return 0;
}


/*
처음 풀었을 때, 테스트케이스 5개 중에 2개가 시간 초과 났다. 

숫자 하나를 기준으로(90), 모든 숫자와 비교하면서 등수를 구한다. 
그 다음 숫자를 기준으로(85) 모든 숫자와 비교하면서 등수를 구한다. 

 
*/
