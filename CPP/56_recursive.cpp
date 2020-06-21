#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

// 56. 재귀함수 분석  

void Print(int num){
	
	if(num - 1 == 0){
		printf("%d ", num);
		return;
	}else{
		Print(num-1);
		printf("%d ", num);
	}
}
 
int main(int argc, char** argv){

	int num;
	
	freopen("input.txt", "rt", stdin);
	
	scanf("%d", &num);   
	
	Print(num);

	return 0;
}

