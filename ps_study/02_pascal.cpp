#include <stdio.h> 
#include <vector> 
#include <algorithm>
using namespace std;


int mul(int input){

	int res = 1, i = 1;
	
	if(input != 0){
	
		while( i <= input){
			res *= i;
			i++;
		}
	}

	return res;
}

int main(int argc, char** argv) {

	// 요소 배열, 자료 개수, 반복문에 필요한 변수들.  
	char str[101];
	int num=0, i=0, j=0; 
	
	freopen("input.txt", "rt", stdin);
		
	scanf("%d", &num); 

	for(i=0; i<num; i++){

		for(j=0; j<=i; j++){
			
			//printf("(%d %d) ", i, j);
			
			if(j==0){
				printf("1 ");
			}else{
				printf("%d ", mul(i) / (mul(j) * mul(i-j)));
			}

		}
		
		printf("\n");
	}

	return 0;
	
}

