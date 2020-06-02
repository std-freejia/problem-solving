#include <stdio.h> 
#include <vector> 
#include <algorithm>
using namespace std;

//진영이의 러브레터


int main(int argc, char** argv) {

	// 요소 배열, 자료 개수, 반복문에 필요한 변수들.  
	char str[101];
	int num=0, i=0, j=0, shift = 0; 
	
	freopen("input.txt", "rt", stdin);
		
	scanf("%d\n", &num); // 숫자를 입력받고 나서 문자열을 연이어 입력받는 것  
    gets(str);

    printf("%d\n", num);
	printf("%s", &str);
	
	printf("\n"); 

	//printf("%d %d %d %d %d %d\n", 'a', 'z', 'A', 'Z', '0', '9');
	/*
	 'a', 'z', 97~122 
	 'A', 'Z', 65~90
	 '0', '9' 48~57
	*/
	
	while(str[i] != '\0'){
		
		//printf("%c ", str[i]);
		
		shift = str[i] + num;
		
		if(shift > 122 && str[i] <= 122) {
			shift -= 58;
		}else if(shift > 90 && str[i] <= 90){
			shift -= 43;
		}else if(shift > 57 && str[i] <= 57){ 
			shift += 39 ;
		}
		
		if(str[i] == 32){ // 띄어쓰기 공백. 
			printf(" ");
		}else{
			printf("%c", shift);
		}
		//printf("%d %d %c\n", str[i], shift, shift);
		
		i++;
	}
	return 0;
	
}



 