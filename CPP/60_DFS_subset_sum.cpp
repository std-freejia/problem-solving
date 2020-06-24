#include <stdio.h>
#include <algorithm>
#include <stack>
#include <vector> 
using namespace std;

// 60. 합이 같은 부분집합 (DFS 아마존인터뷰) 

int arr[11], check[11];
int length_limit; // 원소 개수  
bool result_flag = 0; // "NO" 로 초기화  

bool Calculate_Sum(){
	
	int i, zero, one = 0;
	
	for(i=1; i<=length_limit; i++){
		
		if(check[i] == 0){
			zero += arr[i];
		}else{
			one += arr[i];
		}
	}
	
	//printf("%d %d\n", zero, one);
	
	if(zero == one){
		zero = 0, one = 0;
		return 1;
	}else{
		zero = 0, one = 0;
		return 0;
	}
}

void DFS(int length){
	
	if(length > length_limit){
		
		if(Calculate_Sum()){
			result_flag = 1; // "YES"
		}
		return;
		
	}else{
		
		check[length] = 1; 
		DFS(length+1);
		
		check[length] = 0; 
		DFS(length+1);
	}
}

int main(int argc, char** argv){
	
	//freopen("input.txt", "rt", stdin);
	
	int i = 0;
	
	scanf("%d", &length_limit);
	
	for(i=1; i<=length_limit; i++){
		scanf("%d", &arr[i]);
	}
	
	DFS(1);
	
	if(result_flag){
		printf("YES"); 
	}else{
		printf("NO"); 
	}
	
	return 0;
} 


/*
59번 문제에서 배운 DFS 를 활용해서 풀었는데 처음에는 테스트케이스를 통과하지 못했다. 
Calculate_Sum() 에서 zero와 one 을 누적한 부분이 이상하게 출력되는 것을 확인하고나서, 
zero, one = 0 초기화를 해주고 함수를 종료하도록 수정했다. 그다음에는 테케를 전부 통과했다.  

*/
