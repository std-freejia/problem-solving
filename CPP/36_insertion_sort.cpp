#include <stdio.h> 
#include <vector> 
#include <algorithm>
using namespace std;

// 36. 삽입정렬  

/*

N개이 숫자가 입력되면 오름차순으로 정렬하여 출력하는 프로그램을 작성하세요.
정렬하는 방법은 삽입정렬입니다.


* 입력설명  
첫 번째 줄에 자연수 N(1<=N<=100)이 주어집니다.
두 번째 줄에 N개의 자연수가 공백을 사이에 두고 입력됩니다. 각 자연수는 정수형 범위 안에 있습니다. 

* 출력설명 
오름차순으로 정렬된 수열을 출력합니다.
 
* 입력예제1
6
11 7 5 6 10 9

* 출력예제1
5 6 7 9 10 11

*/

int main(int argc, char** argv){
		
	int arr[100], num, temp, i, j;
	
	freopen("input.txt", "rt", stdin);

	scanf("%d", &num);
	
	for(i=0; i<num; i++){
		scanf("%d", &arr[i]);
	}

	for(i=1; i<num; i++){
		
		temp = arr[i]; // 비교 집합 중에서 맨 오른쪽이 가장 큰 수인지 확인  
		
		for(j=i-1; j>=0; j--){ // 오른쪽에서 왼쪽으로 순회한다. 
			if(arr[j] > temp) arr[j+1] = arr[j];
			else break;
		}
		
		arr[j+1] = temp; // 빈 곳에 temp를 삽입  
	}	
	
	for(i=0; i<num; i++){
		printf("%d ", arr[i]);
	}
	
	return 0;
}


