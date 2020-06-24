#include <stdio.h>
#include <algorithm>
#include <stack>
#include <vector> 
using namespace std;

// 60. ���� ���� �κ����� (DFS �Ƹ������ͺ�) 

int arr[11], check[11];
int length_limit; // ���� ����  
bool result_flag = 0; // "NO" �� �ʱ�ȭ  

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
59�� �������� ��� DFS �� Ȱ���ؼ� Ǯ���µ� ó������ �׽�Ʈ���̽��� ������� ���ߴ�. 
Calculate_Sum() ���� zero�� one �� ������ �κ��� �̻��ϰ� ��µǴ� ���� Ȯ���ϰ���, 
zero, one = 0 �ʱ�ȭ�� ���ְ� �Լ��� �����ϵ��� �����ߴ�. �״������� ���ɸ� ���� ����ߴ�.  

*/
