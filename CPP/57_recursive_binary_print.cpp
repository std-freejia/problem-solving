#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

// 57. 재귀함수 이진수 출력   

void Binary(int num){
	
	if(num/2 == 1){
		printf("%d", num/2);
		printf("%d", num%2);
		return;
	}else{
		Binary(num/2);
		printf("%d", num%2);
	}
}
 
int main(int argc, char** argv){

	int num;
	
	//freopen("input.txt", "rt", stdin);

	scanf("%d", &num);   
	
	Binary(num);

	return 0;
}


