#include <stdio.h> 
#include <algorithm>

// 16. anagram 

/*
애너그램은 문자의 순서를 바꿔서 다른 단어를 만드는 놀이입니다. 
 
길이가 같은 두 개의 단어가 주어지면 두 단어가 아나그램인지 판별하는 프로그램을 작성하세
요. 
아나그램 판별시 대소문자가 구분됩니다.
단어의 길이는 100을 넘지 않습니다.  

input.txt
AbaAeCe
baeeACA
*/

int main(int argc, char** argv) {
	
	char str[101]; // 입력받은 단어  
	int n=0, i=0; 
	int a[53]={0, }, b[53]={0, }; 
	
	//freopen("input.txt", "rt", stdin);	

	// a 배열  
	scanf("%s", &str);	

	for(i = 0; str[i] != '\0'; i++){
		if(str[i]<=90 && str[i]>=65){ // 대문자라면,  
			a[str[i]-64]++;
		}else if(str[i]<=122 && str[i]>=97){ // 소문자라면,
			a[str[i]-70]++;
		}
		
	} 
	
	// b 배열  
	scanf("%s", &str);	

	for(i = 0; str[i] != '\0'; i++){
		if(str[i]<=90 && str[i]>=65){ // 대문자라면,  
			b[str[i]-64]++;
		}else if(str[i]<=122 && str[i]>=97){ // 소문자라면,
			b[str[i]-70]++;
		}
		
	} 
	

	// 두 배열이 똑같은지 검사 
	for(i=1; i<=52; i++){
		if(a[i] != b[i]){
			printf("NO\n");
			exit(0); //프로그램 종료   algorithm 에서 지원. 
		}
	}
	
	printf("YES\n"); 
	
	return 0;
}

/* 문제 해설  

해싱 기법을 이용하자. 

알파벳은 아스키코드 번호가 있다. 대문자 65~90, 소문자 97~122 
대소문자 합쳐서 52개의 알파벳이 있다.  

알파벳 대소문자의 아스키코드 숫자와 int배열의 인덱스와 대응시킨다. 
두 문자 배열의 알파벳 카운팅이 동일하다면 애나그램이다.  

A~Z : 65~90 이니까 여기서 64를 뺀다. 
-> 배열 인덱스 1~26 에 해당.  

a~z : 97~122 인데, 여기서 70을 뺀다.  
-> 배열 인덱스 27~52 에 해당. 

*/

