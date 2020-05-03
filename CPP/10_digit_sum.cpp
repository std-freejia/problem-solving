#include <stdio.h> 

// 10. 자릿수의 합  
/*
N개의 자연수가 입력되면 각 자연수의 자릿수의 합을 구하고, 그 합이 최대인 자연수를 출력
하는 프로그램을 작성하세요. 
각 자연수의 자릿수의 합을 구하는 함수를 int digit_sum(int x)를
꼭 작성해서 프로그래밍 하세요
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


