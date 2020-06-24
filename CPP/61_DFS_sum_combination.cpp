#include <stdio.h>
#include <algorithm>
#include <vector> 
using namespace std;

// 61. Ư�� �� �����  

/*

N���� ���ҷ� ������ �ڿ��� ������ �־����ϴ�.  
������ ���ҿ� ��+��, ��-�� ������ ����Ͽ� Ư������ M�� ����� ��찡 �� ���� �ִ��� ����ϴ� ���α׷��� �ۼ��ϼ���. 
�� ���Ҵ� ���꿡 �� ���� ����մϴ�.
���� ��� {2, 4, 6, 8}�� �Էµǰ�, M=12�̸�
2+4+6=12
4+8=12
6+8-2=12
2-4+6+8=12
�� �� 4������ ��찡 �ֽ��ϴ�. 
��������� ��찡 �������� ������ -1�� ����մϴ�.  

�� �Է¼���
ù ��° �ٿ� �ڿ��� N(1<=N<=10)�� M(1<=M<=100) �־����ϴ�.
�� ��° �ٿ� ������ ���� N���� �־����ϴ�. �� ���Ҵ� �ߺ����� �ʽ��ϴ�.  

�� ��¼���
����� ���� ����մϴ�. ��������� ��찡 �������� ������ -1�� ����մϴ�.  

*/


int arr[11];
int check[11];
int arr_size, target, cnt; 
bool flag_end = false;


bool Sum_check(){ // check �迭�� 1, 2, 0 �� �������� target �Ǵ��� Ȯ�� 
 
	int i = 0, temp_sum = 0;
	
	for (i=1; i<=arr_size; i++){
		
		if(check[i] == 1){ // ����� ����  
			temp_sum += arr[i];
		}else if(check[i] == 2){ // ������ ����  
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
	
	if(level > arr_size){ // �κ����� �ϼ�  
	
		Sum_check();
		
		return; 
		
	}else{
		
		check[level] = 1; // ����� ���տ� ����
		DFS(level+1);
		 
		check[level] = 2; // ������ ���տ� ���� 
		DFS(level+1);
		
		check[level] = 0; // ���� ����.  
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


/* ���� 

59, 60�� ������ �����Ѵ�(1) / ���Ѵ�(0) �� �����ߴ�.
61�� ������ ����� ����(1) / ������ ����(2) / �ƿ� ���þ���.(0) 
�̷��� 3������ �����ߴ�.   

*/
