#include <stdio.h> 
#include <vector> 
#include <algorithm>
using namespace std;


// 34. ��������  

/*
N���� ���ڰ� �ԷµǸ� ������������ �����Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
�����ϴ� ����� ���������Դϴ�.

ù ��° �ٿ� �ڿ��� N(1<=N<=100)�� �־����ϴ�.
�� ��° �ٿ� N���� �ڿ����� ������ ���̿� �ΰ� �Էµ˴ϴ�. �� �ڿ����� ������ ���� �ȿ�
�ֽ��ϴ�. 

�Է�
6
13 23 11 7 5 15

���
5 7 11 13 15 23

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

    for(i=0; i<num-1; i++){ // num-1 ��ŭ ��ȸ  
        
        for(j=0; j<num-(i+1); j++){ // ������ ��Ұ� 1���� �پ��� 
            
            if(arr[j] > arr[j+1]){ // ��ȯ ����
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

