#include <stdio.h> 
#include <math.h>

// 11. ������ �� ����(small) total_count_small 

/*
�ڿ��� N�� �ԷµǸ� 1���� N������ �ڿ����� ���̿� ���� �� �� ���ڴ� �� �� �������� ���ϴ� ���α׷��� �ۼ��ϼ���.

���� ��� 1���� 15������ 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 0, 1, 1, 1, 2, 1, 3, 1, 4, 1, 5����
�� 21���� �������ϴ�. 
 
*/

/* input.txt
15
*/


int main(int argc, char** argv) {
	
	int num=0, count=0, i=0, length=1, ori_num=0, temp=0;
	//freopen("input.txt", "rt", stdin);

	scanf("%d", &num);
	
	ori_num = num;

	while(ori_num > 10){ // �ڸ� �� length ���ϱ�  
		ori_num /= 10;
		length++;
	}	

	while(length > 0){

		count += ( (num-(int)pow(10, length-1))*length + 1);
		num = pow(10, length-1);
		length--;

	}
 
	printf("%d\n", count);
	
	return 0;
}

