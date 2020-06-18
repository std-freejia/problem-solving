#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// 49. ����� �ִ�   maximum_of_blocks

/*
 
�������� ���鿡�� �� �ܸ�� ������ ���鿡�� �� �ܸ��� �ְ� �ִ� ��ϰ����� ����Ͽ� ����� ������ ���鿡�� �� ������� ����� ������ �߽��ϴ�.
������ ����� �״µ� ����ؾ� �� �ִ� ������ ����ϴ� ���α׷��� �ۼ��ϼ���.

���鿡���� ���� ������ ������ ���鿡���� ���� ������ �־����� ����� �� �ִ� ����� ���� ������ ����ϼ���.

�� �Է¼���
ù �ٿ� ����� ũ�� N(3<=N<=10)�� �־����ϴ�. ����� ũ��� ���簢�� N*N�Դϴ�.
�� ��° �ٿ� N���� ���鿡���� ���� ������ ���� �������� �־����ϴ�.
�� ��° �ٿ� N���� ������ ���� ���� ������ ���ʺ��� �־����ϴ�.
����� ���̴� 10 �̸��Դϴ�.

�� ��¼���
ù �ٿ� ����� �ִ� ������ ����մϴ�.

*/


int main(int argc, char** argv){
	
	int i = 0, j = 0, size_of_block = 0, min = 0;

	//freopen("input.txt", "rt", stdin);

	scanf("%d", &size_of_block); // �Է¹ޱ� ����  
	
	vector<int> front(size_of_block), right(size_of_block);
	
	for(i=0; i<size_of_block; i++){
		scanf("%d", &front[i]);
	}

	for(i=size_of_block-1; i>=0; i--){
		scanf("%d", &right[i]);
	} // �Է� �ޱ� ��.
	
	
	for(i=0; i<size_of_block; i++){
		
		for(j=0; j<size_of_block; j++){
			
			if(right[i] < front[j]){
				min += right[i];
			}else{
				min += front[j];
			}
		}
	} 
	
	printf("%d", min);
	
	return 0;
}


