#include <stdio.h> 
#include <vector> 
#include <algorithm>
using namespace std;


// 29. 3의 개수는? (small)  count_of_3

/*
자연수 N이 입력되면 1부터 N까지의 자연수를 종이에 적을 때 각 숫자 중 3의 개수가 몇 개 있는지 구하려고 합니다.
예를 들어 1부터 15까지는 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 0, 1, 1, 1, 2, 1, 3, 1, 4, 1, 5으로 3의 개수는 2개입니다.
자연수 N이 입력되면 1부터 N까지 숫자를 적을 때, 3의 개수가 몇 개인지 구하여 출력하는 프로그램을 작성하세요.

첫 줄에 자연수의 개수 N(3<=N<=100,000)이 주어집니다.

입력 input.txt
15

출력 
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

