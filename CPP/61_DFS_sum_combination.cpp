#include <stdio.h>
#include <algorithm>
#include <vector> 
using namespace std;

// 61. 특정 수 만들기  

/*

N개의 원소로 구성된 자연수 집합이 주어집니다.  
집합의 원소와 ‘+’, ‘-’ 연산을 사용하여 특정수인 M을 만드는 경우가 몇 가지 있는지 출력하는 프로그램을 작성하세요. 
각 원소는 연산에 한 번만 사용합니다.
예를 들어 {2, 4, 6, 8}이 입력되고, M=12이면
2+4+6=12
4+8=12
6+8-2=12
2-4+6+8=12
로 총 4가지의 경우가 있습니다. 
만들어지는 경우가 존재하지 않으면 -1를 출력합니다.  

▣ 입력설명
첫 번째 줄에 자연수 N(1<=N<=10)와 M(1<=M<=100) 주어집니다.
두 번째 줄에 집합의 원소 N개가 주어집니다. 각 원소는 중복되지 않습니다.  

▣ 출력설명
경우의 수를 출력합니다. 만들어지는 경우가 존재하지 않으면 -1를 출력합니다.  

*/


int arr[11];
int check[11];
int arr_size, target, cnt; 
bool flag_end = false;


bool Sum_check(){ // check 배열의 1, 2, 0 을 기준으로 target 되는지 확인 
 
	int i = 0, temp_sum = 0;
	
	for (i=1; i<=arr_size; i++){
		
		if(check[i] == 1){ // 양수로 선택  
			temp_sum += arr[i];
		}else if(check[i] == 2){ // 음수로 선택  
			temp_sum -= arr[i];
		}
	}	
	
	//printf("temp_sum : %d\n", temp_sum);
	
	if(temp_sum == target){
		cnt++;
		flag_end = true;
	}

}

void DFS(int level){
	
	if(level > arr_size){ // 부분집합 완성  
	
		Sum_check();
		
		return; 
		
	}else{
		
		check[level] = 1; // 양수로 집합에 선택
		DFS(level+1);
		 
		check[level] = 2; // 음수로 집합에 선택 
		DFS(level+1);
		
		check[level] = 0; // 선택 안함.  
		DFS(level+1);
		
	}
}

int main(void){
	
	//freopen("input.txt", "rt", stdin);
	
	int i = 0;
	
	scanf("%d %d", &arr_size, &target);
			 
	for(i = 1; i <= arr_size; i++){
		scanf("%d", &arr[i]);
	}
	
	DFS(1);
	
	if(cnt > 0 ){
		printf("%d", cnt);
	}else{
		printf("%d", -1);

	}

	return 0;
} 


/* 설계 

59, 60번 문제는 선택한다(1) / 안한다(0) 를 구분했다.
61번 문제는 양수로 선택(1) / 음수로 선택(2) / 아예 선택안함.(0) 
이렇게 3가지로 구분했다.   

*/
