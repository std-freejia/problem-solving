#include <stdio.h>
#include <algorithm>
#include <stack>
#include <vector> 
using namespace std;

// 59. 부분집합  (DFS 완전탐색)


int arr[11], num;

void Print(){
	
	int i = 0;
	
	for(i=1; i<=num; i++){
		if(arr[i] == 1) printf("%d", i);
	}
	puts("");
	
	return;
}

void DFS(int level){
	
	if(level > num ){
		
		// arr 에서 1로 선택한 레벨만 출력  
		Print(); 
		return; 
		
	}else{
		
		arr[level] = 1; // 선택함  (같은 레벨의 왼쪽자식) 
		DFS(level+1);
		
		arr[level] = 0; // 선택안함  (같은 레벨의 오른쪽자식)
		DFS(level+1);
	}


	return; 
} 

int main(int argc, char** argv){
	
	freopen("input.txt", "rt", stdin);
	
	scanf("%d", &num);
	
	DFS(1);
	
	return 0;
} 
