#include <stdio.h> 
#include <vector> 
#include <algorithm>
using namespace std;


// 29. 3�� ������? (small)  count_of_3

/*
�ڿ��� N�� �ԷµǸ� 1���� N������ �ڿ����� ���̿� ���� �� �� ���� �� 3�� ������ �� �� �ִ��� ���Ϸ��� �մϴ�.
���� ��� 1���� 15������ 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 0, 1, 1, 1, 2, 1, 3, 1, 4, 1, 5���� 3�� ������ 2���Դϴ�.
�ڿ��� N�� �ԷµǸ� 1���� N���� ���ڸ� ���� ��, 3�� ������ �� ������ ���Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.

ù �ٿ� �ڿ����� ���� N(3<=N<=100,000)�� �־����ϴ�.

�Է� input.txt
15

��� 
2 
*/


int main(int argc, char** argv) {
	
	
	int num = 0, i=0, cnt=0, temp=0; 
	 
	//freopen("input.txt", "rt", stdin);	

	scanf("%d", &num);

	for(i=1; i <= num; i++){
		temp = i;
		
		while(1){
			if(temp % 10 == 3){
				cnt++;
			}
			temp /= 10;
			
			if(temp<1){
				break;
			}
		} 
	}

	printf("%d", cnt);
	return 0;
}

