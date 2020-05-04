#include <stdio.h> 
#include <math.h>

// 12. 숫자의 총 개수(large) total_count_large

/*
제한시간 1초.
 
자연수 N이 입력되면 1부터 N까지의 자연수를 종이에 적을 때 각 숫자는 몇 개 쓰였는지 구하는 프로그램을 작성하세요.

예를 들어 1부터 15까지는 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 0, 1, 1, 1, 2, 1, 3, 1, 4, 1, 5으로
총 21개가 쓰였습니다. 
 
*/

/* input.txt
15
*/

int main(int argc, char** argv) {
	
	// 입력받은 숫자, 확인한  숫자, 자리수, 자리수 마다의 개수, 필요한 숫자 총 개수 
	int num, sum=0, count = 1, d=9, res=0;
	//freopen("input.txt", "rt", stdin);

	scanf("%d", &num); // num = 15 인 경우,  
	
	while(sum+d < num){ // 15가 1자리수 보다 큰 수인지. 
		
		res = res + (count*d); // 1자리수 * 9개  (개수를 센다) 
		sum = sum + d; // 1자리수 9개를 더해서 누적한다.  (어디까지 확인했는지) 
		count++; // 1자리수 -> 2자리수 (자리수)  
		d = d * 10; // 9개 -> 90개 (자리수 마다의 개수 )  
	}
	
	res += (num-sum)*count;
	
	printf("%d\n", res);
	
	return 0;
}


/*

int main(int argc, char** argv) {
	
	// 입력받은 숫자, 누적되는 숫자, 자리수, 자리수 마다의 개수  
	int num, sum=0, count = 1, d=9, res = 0;
	//freopen("input.txt", "rt", stdin);

	scanf("%d", &num); // num = 256 
	
	while(sum+d < num){ // sum  d     count     res   
						// 0    9개   1자리수   9
						// 9    90개  2자리수   189 
						// 99   900개 3자리수   
		res = res + (count*d); // 1자리수 * 9개  (개수를 센다) 
		sum = sum + d; // 1자리수 9개를 더해서 누적한다.  
		count++; // 1자리수 -> 2자리수  
		d = d*10; // 9개 -> 90개 (자리수 마다의 개수 )  
	}
	
	// 99까지 개수를 셌으니까 100부터 256 까지 숫자 몇개인지 센다.  
	res += (num-sum)*count;
	
	printf("%d\n", res);
	
	return 0;
}
*/

