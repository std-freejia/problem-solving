#include <stdio.h>
#include <algorithm>
#include <stack>
#include <vector> 
using namespace std;

// 59. �κ�����  (DFS ����Ž��)


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
		
		// arr ���� 1�� ������ ������ ���  
		Print(); 
		return; 
		
	}else{
		
		arr[level] = 1; // ������  (���� ������ �����ڽ�) 
		DFS(level+1);
		
		arr[level] = 0; // ���þ���  (���� ������ �������ڽ�)
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