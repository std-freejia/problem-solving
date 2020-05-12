#include <stdio.h> 
#include <vector> 
#include <algorithm>
using namespace std;


// 26. 마라톤  marathon

/*
각 선수의 평소 실력은 정수로 주어지는데 더 큰 값이 더 좋은 실력을 의미한다. 
현재 달리고 있는 선수를 앞에서 부터 표시했을 때 평소 실력이 각각 2, 8, 10, 7, 1, 9, 4, 15라고 하면
각 선수가 얻을 수 있는 최선의 등수는 (같은 순서로) 각각 1, 1, 1, 3, 5, 2, 5, 1이 된다. 

예를 들어, 4번째로 달리고 있는 평소 실력이 7인 선수는 그 앞에서 달리고 있는 선수들 중 평소 실력이 2인 선수만 앞지르는 것이 가능하고 
평소실력이 8과 10인 선수들은 앞지르는 것이 불가능하므로, 최선의 등수는 3등이 된다.
선수들의 평소 실력을 현재 달리고 있는 순서대로 입력 받아서 각 선수의 최선의 등수를 계산하는 프로그램을 작성하시오.

첫째 줄에는 선수의 수를 의미하는 정수 N이 주어진다. 
N은 3 이상 10,000 이하이다. 
다음 줄에는 N개의 정수가 주어진다. 이 값들은 각 선수들의 평소 실력을 앞에서 달리고 있는 선수 부터 제시한 것이다. 
각 정수는 1 이상 100,000 이하이다. 
참가한 선수의 평소실력은 같을 수 있다. 
그리고 실력이 같다면 앞에 달리는 선수를 앞지를 수 없다. 


input.txt
8
2 8 10 7 1 9 4 15
*/


int main(int argc, char** argv) {

	int total = 0, i=0, j=0, temp=0, cnt=0;
	 
	//freopen("input.txt", "rt", stdin);	
	scanf("%d", &total);
	
	vector<int> runner(total);
	vector<int> rank(total, 1);

	for(i=0; i<total; i++){
		scanf("%d", &runner[i]);
	}
	
	printf("1 "); // 첫 사람은 무조건 일등. 
	
	for(i=1; i<total; i++){

		cnt=1;
		
		for(j=i-1; j>=0; j--){
			if(runner[i]<=runner[j]){
				cnt++;
			}
		}
		
		printf("%d ", cnt);
	}
	
	return 0;
}

