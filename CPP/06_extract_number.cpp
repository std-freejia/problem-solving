#include <stdio.h> 
using namespace std;

// 6. 숫자만 추출  extract_number
// 문자에서 숫자만 추출하여 자연수를 출력합니다. 
// 그리고 자연수의 약수의 개수를 출력합니다.  

/* input.txt
g0en2Ts8eSoft
*/
int main(int argc, char** argv) {
	
	//freopen("input.txt", "rt", stdin);

	char arr[100];
	int res = 0, cnt = 0, i;
	
	scanf("%s", &arr);
	
	// '\0' 문자열의 끝을 의미하는 널문자  
	for(i=0; arr[i]!='\0'; i++){
		if(arr[i] >= 48 && arr[i]<= 57){ // 숫자0~9에 해당하는 ASCII  
			res = res*10 + (arr[i]-48);
		}
	}
	printf("%d\n", res);
	
	// 약수의 개수 구하기 
	for(i=1; i<=res; i++){
		if(0 == res%i){
			cnt++;
		}
	} 
	
	printf("%d\n", cnt);

	return 0;
}


