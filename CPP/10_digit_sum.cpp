#include <stdio.h> 

// 10. �ڸ����� ��  
/*
N���� �ڿ����� �ԷµǸ� �� �ڿ����� �ڸ����� ���� ���ϰ�, �� ���� �ִ��� �ڿ����� ���
�ϴ� ���α׷��� �ۼ��ϼ���. 
�� �ڿ����� �ڸ����� ���� ���ϴ� �Լ��� int digit_sum(int x)��
�� �ۼ��ؼ� ���α׷��� �ϼ���
*/

/* input.txt
5
125 15232 79 1325 97
*/

int digit_sum(int x){
	int sum = 0;
	
	while(1 <= x){
		sum += x%10;
		x = x/10;
	}
	
	return sum;
}

int main(int argc, char** argv) {
	
	int repeat=0, i=0, j=0, max=-2147000000, digit_res=0, max_num=0; 
	//freopen("input.txt", "rt", stdin);
	 
	scanf("%d", &repeat);
	
	for(i=0; i<repeat; i++){
		scanf("%d", &j);
		digit_res = digit_sum(j);
		
		if(max < digit_res){
			max = digit_res;
			max_num = j;

		}else if(max == digit_res){
			if(max_num < j){
				max_num = j;
			}
		}
	}
	
	printf("%d", max_num);
	
	return 0;
}


