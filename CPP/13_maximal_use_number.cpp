#include <stdio.h> 
#include <string.h>

// 13. 가장 많이 사용된 자릿수  

/*
자연수 N이 입력되면 N의 숫자 중에 '가장 많이 사용된 숫자'를 출력하세요.  
예를 들어  1230565625 가 입력되면, 5가 3번 사용되어 '가장 많이 사용된 숫자'가 됩니다.
답이 여러 개인 경우 그 중 가장 큰 수를 출력하세요.  
*/

/* input.txt
1230565625
*/

int main(int argc, char** argv) {
	
	int arr[10]={0, }, max=0, max_index = 0, i=0, num=0; 
	char input[101]; // 숫자를 담을 배열  
	
	//freopen("input.txt", "rt", stdin);
	scanf("%s", &input);
	
	// 한 자리 마다 읽는다. 배열 인덱스 마다 count를 증가 시킨다.  
	for(i=0; input[i] != '\0'; i++){
		num = input[i]-48;
		//printf("%d ", num);
		arr[num]++;
	}
	
	for(i=sizeof(arr)/sizeof(int)-1; i>=0; i--){
		if(max < arr[i]){
			max = arr[i];
			max_index = i;
		}
	}
	 
	printf("%d", max_index);
	
	return 0;
}

