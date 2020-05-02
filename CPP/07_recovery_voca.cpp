#include <stdio.h> 
using namespace std;

// 7. 영어 단어 복구 recovery_voca
// 영어단어를 원래의 표현대로 공백을 제거하고 소문자화 시켜 출력하는 프로그램을 작성하세요.

int main(int argc, char** argv) {
	
	//freopen("input.txt", "rt", stdin);
	char input[101], res[101];
	int i, pos=0;
	
	//줄바꿈까지 문자로 읽어야 하니까 파일을 읽는 gets() 이용
	gets(input);
	
	for(i=0; input[i]!='\0'; i++){
		if(input[i] != ' '){
			if(input[i]>=65 && input[i]<=90){ // 대문자라면, 소문자로 변환( +32) 
				res[pos++] = input[i]+32;
				// A 65, a 97 
			}else{ // 소문자라면 
				res[pos++] = input[i];
			}
		}
	} 
	res[pos]= '\0'; //마지막에 NULL
	printf("%s\n", res); 
	
	return 0;
}


