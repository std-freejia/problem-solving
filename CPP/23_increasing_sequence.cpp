#include <stdio.h> 
#include <vector> 

// 23. 연속 부분 증가수열   increasing_sequence 

/*
N개의 숫자가 나열된 수열이 주어집니다. 
이 수열 중 연속적으로 증가하는 부분 수열을 최대길이를 구하여 출력하는 프로그램을 작성하세요.
만약 N=9이고
5 7 3 3 12 12 13 10 11 이면 “3 3 12 12 13”부분이 최대 길이 증가수열이므로 그 길이인
5을 출력합니다. 
값이 같을 때는 증가하는 걸로 생각합니다.

input.txt
9
5 7 3 3 12 12 13 10 11

*/


int main(int argc, char** argv) {

	int i=0, count=0, length=1, max=-2147000000;
	
	//freopen("input.txt", "rt", stdin);	

	scanf("%d", &count);
	
	// 배열 동적 할당  
	std::vector<int> num(count);
	
	for(i=0; i<count; i++){
		scanf("%d", &num[i]);
	}
		
	for(i=1; i<count; i++){
		
		if(num[i-1] <= num[i]){ //이전보다 같거나 크다 length++
			length++;
			
			if (max < length){ // max를 계속 갱신  
				max = length;
			}
		}else{ // 아니다 length = 0 
			length = 1;
		}
		//printf("%d %d, length:%d\n", num[i-1], num[i], length);
	}
	
	printf("%d", max);

	return 0;
}

