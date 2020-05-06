#include <stdio.h> 

// 14. 뒤집은 소수  reversed prime

/*
N개의 자연수가 입력되면 각 자연수를 뒤집은 후 그 뒤집은 수가 소수이면 그 수를 출력하는
프로그램을 작성하세요. 
 
예를 들어, 32를 뒤집으면 23이고, 23은 소수이다. 그러면 23을 출력한다. 
*/

/* input.txt
5
32 55 62 3700 250
*/

bool isPrime(int x){ // 소수인지 판별
	int i = 0;
	
	// 1은 소수가 아니므로 주의!  
	if(x == 1) return false; 
	
	for(i=2; i<x; i++){
		if(x%i == 0){
			return false;
		}
	}
	
	return true;
}

int reverse(int x){ // 자연수 뒤집기 
	int res=0, temp=0;
	
	while(x>0){
		temp = x%10;
		res = res*10 + temp;
		x = x/10;
	}

	return res;
}

int main(int argc, char** argv) {
	
	int cnt=0, i=0, num=0;
	//freopen("input.txt", "rt", stdin);
	
	scanf("%d", &cnt);
	
	for(i=0; i<cnt; i++){
		scanf("%d", &num);
		num = reverse(num);
		
		if(isPrime(num)){
			printf("%d ", num);
		}
	}
	
	return 0;
}


