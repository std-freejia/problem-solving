#include <stdio.h> 
#include <vector> 
#include <algorithm>
using namespace std;

// 36. ��������  

/*

N���� ���ڰ� �ԷµǸ� ������������ �����Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
�����ϴ� ����� ���������Դϴ�.


* �Է¼���  
ù ��° �ٿ� �ڿ��� N(1<=N<=100)�� �־����ϴ�.
�� ��° �ٿ� N���� �ڿ����� ������ ���̿� �ΰ� �Էµ˴ϴ�. �� �ڿ����� ������ ���� �ȿ� �ֽ��ϴ�. 

* ��¼��� 
������������ ���ĵ� ������ ����մϴ�.
 
* �Է¿���1
6
11 7 5 6 10 9

* ��¿���1
5 6 7 9 10 11

*/

int main(int argc, char** argv){
		
	int arr[100], num, temp, i, j;
	
	freopen("input.txt", "rt", stdin);

	scanf("%d", &num);
	
	for(i=0; i<num; i++){
		scanf("%d", &arr[i]);
	}

	for(i=1; i<num; i++){
		
		temp = arr[i]; // �� ���� �߿��� �� �������� ���� ū ������ Ȯ��  
		
		for(j=i-1; j>=0; j--){ // �����ʿ��� �������� ��ȸ�Ѵ�. 
			if(arr[j] > temp) arr[j+1] = arr[j];
			else break;
		}
		
		arr[j+1] = temp; // �� ���� temp�� ����  
	}	
	
	for(i=0; i<num; i++){
		printf("%d ", arr[i]);
	}
	
	return 0;
}


