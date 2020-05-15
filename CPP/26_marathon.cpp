#include <stdio.h> 
#include <vector> 
#include <algorithm>
using namespace std;


// 26. ������  marathon

/*
�� ������ ��� �Ƿ��� ������ �־����µ� �� ū ���� �� ���� �Ƿ��� �ǹ��Ѵ�. 
���� �޸��� �ִ� ������ �տ��� ���� ǥ������ �� ��� �Ƿ��� ���� 2, 8, 10, 7, 1, 9, 4, 15��� �ϸ�
�� ������ ���� �� �ִ� �ּ��� ����� (���� ������) ���� 1, 1, 1, 3, 5, 2, 5, 1�� �ȴ�. 

���� ���, 4��°�� �޸��� �ִ� ��� �Ƿ��� 7�� ������ �� �տ��� �޸��� �ִ� ������ �� ��� �Ƿ��� 2�� ������ �������� ���� �����ϰ� 
��ҽǷ��� 8�� 10�� �������� �������� ���� �Ұ����ϹǷ�, �ּ��� ����� 3���� �ȴ�.
�������� ��� �Ƿ��� ���� �޸��� �ִ� ������� �Է� �޾Ƽ� �� ������ �ּ��� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

ù° �ٿ��� ������ ���� �ǹ��ϴ� ���� N�� �־�����. 
N�� 3 �̻� 10,000 �����̴�. 
���� �ٿ��� N���� ������ �־�����. �� ������ �� �������� ��� �Ƿ��� �տ��� �޸��� �ִ� ���� ���� ������ ���̴�. 
�� ������ 1 �̻� 100,000 �����̴�. 
������ ������ ��ҽǷ��� ���� �� �ִ�. 
�׸��� �Ƿ��� ���ٸ� �տ� �޸��� ������ ������ �� ����. 


input.txt
8
2 8 10 7 1 9 4 15
*/


int main(int argc, char** argv) {

	int total = 0, i=0, j=0, temp=0, cnt=0;
	 
	//freopen("input.txt", "rt", stdin);	
	scanf("%d", &total);
	
	vector<int> runner(total);
	vector<int> rank(total, 1);

	for(i=0; i<total; i++){
		scanf("%d", &runner[i]);
	}
	
	printf("1 "); // ù ����� ������ �ϵ�. 
	
	for(i=1; i<total; i++){

		cnt=1;
		
		for(j=i-1; j>=0; j--){
			if(runner[i]<=runner[j]){
				cnt++;
			}
		}
		
		printf("%d ", cnt);
	}
	
	return 0;
}
