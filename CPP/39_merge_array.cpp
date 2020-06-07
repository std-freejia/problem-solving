#include <stdio.h> 
#include <string.h>
#include <vector> 
#include <algorithm>
using namespace std;

// 39. �� �迭 ��ġ��  merge_array

/*
������������ ������ �� �� �迭�� �־����� �� �迭�� ������������ ���� ����ϴ� ���α׷��� �ۼ��ϼ���.

�� �Է¼���
ù ��° �ٿ� ù ��° �迭�� ũ�� N(1<=N<=100)�� �־����ϴ�.
�� ��° �ٿ� N���� �迭 ���Ұ� ������������ �־����ϴ�.
�� ��° �ٿ� �� ��° �迭�� ũ�� M(1<=M<=100)�� �־����ϴ�.
�� ��° �ٿ� M���� �迭 ���Ұ� ������������ �־����ϴ�.
�� �迭�� ���Ҵ� int�� ������ ũ�⸦ ���� �ʽ��ϴ�.

�� ��¼���
������������ ���ĵ� �迭�� ����մϴ�.

*/


int arr_a[101], arr_b[101], res[300];

int main(int argc, char** argv){
	
	// �迭�� ũ�� ����, �ε����� �����ϴ� ���� 3�� (p) �� �� 1�� ������.  
	int a_size, b_size, arr_size, i, p1=1, p2=1, p3=1; 
	
	//freopen("input.txt", "rt", stdin);
	
	// �ʿ��� �迭 3�� : �Է¹޴� �迭 arr_a, arr_b, ����迭 res 
	 
	// �Է¹ޱ� ����  
	scanf("%d", &a_size);
	//vector<int> arr_a(a_size);
		
	for(i=1; i<=a_size; i++){  // ���Ϳ� ���ڸ� �Է¹޴� �ε�����  1 ���� �ϰ� ����.  
		scanf("%d", &arr_a[i]);
	}
	
	scanf("%d", &b_size);
	//vector<int> arr_b(b_size);
		
	for(i=1; i<=b_size; i++){ 
		scanf("%d", &arr_b[i]);
	}// �Է¹ޱ� ��  
	
	// ��� ������ ����  
	//vector<int> res(a_size+b_size);

	// �ε��� ���� 2���� ������ ���� ���� ���� �� ���� p1 �Ǵ� p2�� �̵���Ŵ. 
	while(p1 <= a_size && p2 <= b_size){ // ��� �� ���� �ڱ� ũ�⺸�� Ŀ�� ������. 
		
		if(arr_a[p1] < arr_b[p2]){
			res[p3++] = arr_a[p1++]; 
			// p3�� ������ �Ŀ�, 1���� ���ش�. res[p3]; p3+=1; �� ����.  
		}else{
			res[p3++] = arr_b[p2++]; 
		}
	}
	
	// �� ���� �� res�� ����, �ٸ� �� ���� res�� ������ ������ ��. 
	while(p1 <= a_size) res[p3++] = arr_a[p1++];
	while(p2 <= b_size) res[p3++] = arr_b[p2++];

	for(i=1; i<=a_size+b_size; i++){ // ��� �� ���� �ε��� 1���� ����. 
		printf("%d ", res[i]);
	}
	
	return 0;
}

