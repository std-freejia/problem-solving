#include <stdio.h> 
#include <math.h>

// 11. 숫자의 총 개수(small) total_count_small 

/*
자연수 N이 입력되면 1부터 N까지의 자연수를 종이에 적을 때 각 숫자는 몇 개 쓰였는지 구하는 프로그램을 작성하세요.

예를 들어 1부터 15까지는 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 0, 1, 1, 1, 2, 1, 3, 1, 4, 1, 5으로
총 21개가 쓰였습니다. 
 
*/

/* input.txt
15
*/


int main(int argc, char** argv) {
	
	int num=0, count=0, i=0, length=1, ori_num=0, temp=0;
	//freopen("input.txt", "rt", stdin);

	scanf("%d", &num);
	
	ori_num = num;

	while(ori_num > 10){ // 자리 수 length 구하기  
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

