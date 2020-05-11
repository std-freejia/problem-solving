#include <stdio.h> 
#include <vector> 

// 22. 온도의 최대값  maximum_temperature

/*
온도가 어떤 정수의 수열로 주어졌을 때, 연속적인 며칠 동안의 온도의 합이 가장 큰 값을 알아보고자 한다.

제한 시간 1초. 

첫째 줄에는 두 개의 정수 N과 K가 한 개의 공백을 사이에 두고 순서대로 주어진다. 
첫 번째 정수 N은 온도를 측정한 전체 날짜의 수이다. N은 2 이상 100,000 이하이다. 
두 번째 정수 K는 합을 구하기 위한 연속적인 날짜의 수이다. 
K는 1과 N 사이의 정수이다. 둘째 줄에는 매일 측정한 온도를 나타내는 N개의 정수가 빈칸을 사이에 두고 주어진다. 
이 수들은 모두 -100이상 100 이하이다. 

2<N<100000
1<K<N 

input.txt
10 2
3 -2 -4 -9 0 3 7 13 8 -3
*/


int main(int argc, char** argv) {

	int total=0, i=0, j=0, conti=0, max=-2147000000, sum=0;
	 
	//freopen("input.txt", "rt", stdin);	

	scanf("%d %d", &total, &conti);

	// 벡터로 배열동적할당 
	std::vector<int> temp(total);  // 기본으로 0 초기화.  
	 
	for(i=0; i<total; i++){ // 배열에 담는다  
		scanf("%d", &temp[i]);
	}
	
	// 처음 K개 만큼 누적.  
	for(i=0; i<conti; i++){
		sum += temp[i];
	}
	
	max = sum;

	for(i=conti; i<total; i++){
		
		//printf("%d %d\n", temp[i-conti] , temp[i]);
		sum -= temp[i-conti];
		sum += temp[i];
		
		if(max < sum){
			max = sum;
		}
	}
	
	printf("%d", max);

	return 0;
}

/*
이중 for문으로는 시간 초과가 난다. 
테스트케이스 5개중에 3개만 통과하고, 나머지 2개는 시간 초과 남. 

for문 1개로 해결해야 함.

일단 첫 구간의 합을 구한다. 
이를 기준으로 1개 더하고 1개 빼고를 반복한다.  

*/


