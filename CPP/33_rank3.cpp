#include <stdio.h> 
#include <vector> 
#include <algorithm>
using namespace std;


// 33. 3���� ������? (���� ����) 

/*
N���� ���м����� �־����� �� �� 3���� �� ���м����� ����ϴ� ���α׷��� �ۼ��ϼ���. 
���� �л��� ������ 100���� 3��, 99���� 2��, 98���� 5��, 97���� 3�� �̷������� ������ �����Ǹ� 1���� 3���̸�, 2���� 2���̸�  
3���� 5���� �Ǿ� 98���� 3���� �� ������ �˴ϴ�.

ù ��° �ٿ� �ڿ��� N(1<=N<=100)�� �־����ϴ�.
�� ��° �ٿ� N���� ���м��� ������ ������ ���̿� �ΰ� �Էµ˴ϴ�. ���м��� ������ 100��
���� �������� �Էµ˴ϴ�.

*/

int main(int argc, char** argv) {

	int num=0, arr[101], i=0, j=0, idx=0, tmp=0, rank=0, res=0; 
	
	//freopen("input.txt", "rt", stdin);
	
	scanf("%d", &num);
	
	// ���ڵ� �б� 
	for(i=0; i<num; i++){
		scanf("%d", &arr[i]);
	} 

	for(i=0; i<num-1; i++){ // ��������  
		
		idx = i; // i�� ��������.  
		
		for(j = i+1; j<num; j++){
			
			if(arr[j] > arr[idx]) idx = j;  // ���� ���� '�ε���'�� ����صд�  
			
		}
		
		tmp = arr[i];
		arr[i] = arr[idx];
		arr[idx] = tmp;
	}
	
	for(i=1; i<num; i++){ // 3�� ã��  
		
		if(arr[i-1] > arr[i]){
			rank++;
		}
				
		if(rank == 2){
			printf("%d", arr[i]);
			break; 
		}
	}
		 
	return 0;
	
}

/*

�Է� 
7
80 96 75 82 96 92 100

���
92

*/

