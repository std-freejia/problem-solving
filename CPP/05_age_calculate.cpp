#include <stdio.h> 
using namespace std;

// 5. 나이 계산(문자열 컨트롤) age_calculate
// 주민등록증의 번호가 주어지면 주민등록증 주인의 나이와 성별을 판단하세요. (2019년기준) 
// 주민번호를 char 배열에 넣고, 나이 계산, 성별 판별을 한다.  

/* input.txt
780316-2376152 
*/
int main(int argc, char** argv) {
	
	//freopen("input.txt", "rt", stdin);
	// cin, cout 보다는 scanf, printf 가 빠르다. 
	char num_arr[20];
	int year, age;
	
	scanf("%s", &num_arr);
	
	if('1' == num_arr[7] || '2' == num_arr[7]){ // 1900년대생 
		// 문자 0은 십진수로 48이다. (ASCII 코드 참고)  
		// 'A' 65 'Z' 90 'a' 97 '0' 48 '9' 57
		year = 1900+((num_arr[0]-48)*10 + (num_arr[1]-48));
	}else{ // 2000 년대 생  
		year = 2000+((num_arr[0]-48)*10 + (num_arr[1]-48));
	} 		
	age = 2019-year+1;
	printf("%d ", age);
	
	if('1' == num_arr[7] || '3' == num_arr[7]){
		printf("M\n");
	}else{
		printf("W\n");
	}
	
	return 0;
}


