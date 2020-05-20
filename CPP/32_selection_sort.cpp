#include <stdio.h> 
#include <vector> 
#include <algorithm>
using namespace std;


// 32. ��������    selection_sort

/*
N���� ���ڰ� �ԷµǸ� ������������ �����Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
�����ϴ� ����� ���������Դϴ�.

ù ��° �ٿ� �ڿ��� N(1<=N<=100)�� �־����ϴ�.
�� ��° �ٿ� N���� �ڿ����� ������ ���̿� �ΰ� �Էµ˴ϴ�. �� �ڿ����� ������ ���� �ȿ�
�ֽ��ϴ�. 

�Է�  input.txt
6
13 5 11 7 23 15

��� 
5 7 11 13 15 23 
*/

int main(int argc, char** argv) {
	
	// n : ������ ���� ����
	 
	int a[100], n, idx, i, j, tmp;
	
	freopen("input.txt", "rt", stdin);
	
	scanf("%d", &n);
	
	// ���ڵ� �б� 
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	} 

	for(i=0; i<n-1; i++){
		
		idx = i; // i�� ��������.  
		
		for(j = i+1; j<n; j++){
			
			if(a[j] < a[idx]) idx = j;  // ���� ���� '�ε���'�� ����صд�  
			
		}
		
		tmp = a[i];
		a[i] = a[idx];
		a[idx] = tmp;
		
	}

	for(i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	 
	return 0;
	
}

