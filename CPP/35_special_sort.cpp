#include <stdio.h> 
#include <vector> 
#include <algorithm>
using namespace std;


// 35. Special Sort (���� ���ͺ�) 

/*

N���� ������ �ԷµǸ� ����� �Էµ� ���� �����ؾ� �Ѵ�.
���� ������ ���ʿ� ���������� ���ʿ� �־�� �Ѵ�. 
���� ���������� ���������� �������� ������ ����� �Ѵ�.

ù ��° �ٿ� ���� N(5<=N<=100)�� �־�����, �� ���� �ٺ��� ������ ������ ������ �־�����. 
���� 0�� �Էµ��� �ʴ´�.

���ĵ� ����� ����Ѵ�


�Է¿��� 1 
8
1 2 3 -3 -2 5 6 -6

��¿��� 1
-3 -2 -6 1 2 3 5 6

*/


int main(int argc, char** argv) {

	// ��� �迭, �ڷ� ����, �ݺ����� �ʿ��� ������.  
	int arr[101], num=0, i=0, j=0, temp; 
	
	//freopen("input.txt", "rt", stdin);
	
	scanf("%d", &num);
	
	// ���ڵ� �б� 
	for(i=0; i<num; i++){
		scanf("%d", &arr[i]);
	} 

	for(i=0; i<num-1; i++ ){ 
		
		for(j=0; j<num-i-1; j++){
			
			if(arr[j] > 0 && arr[j+1] < 0){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
    
	for(i=0; i<num; i++){
		printf("%d ", arr[i]);
	} 
		 
	return 0;
	
}

/*
�������ĺ��ٴ� ���������� �����ϴ�. 
�ֳ��ϸ� "���������� ���������� ����"�� �����ؾ� �ϱ� �����̴�.  

���� ���, �ڰ� ������ ��츸 �������ķ� Swap �Ѵ�.  

*/