#include <stdio.h> 
#include <vector> 
#include <algorithm>
using namespace std;


// 32. 선택정렬    selection_sort

/*
N개이 숫자가 입력되면 오름차순으로 정렬하여 출력하는 프로그램을 작성하세요.
정렬하는 방법은 선택정렬입니다.

첫 번째 줄에 자연수 N(1<=N<=100)이 주어집니다.
두 번째 줄에 N개의 자연수가 공백을 사이에 두고 입력됩니다. 각 자연수는 정수형 범위 안에
있습니다. 

입력  input.txt
6
13 5 11 7 23 15

출력 
5 7 11 13 15 23 
*/

int main(int argc, char** argv) {
	
	// n : 정렬할 수의 개수
	 
	int a[100], n, idx, i, j, tmp;
	
	freopen("input.txt", "rt", stdin);
	
	scanf("%d", &n);
	
	// 숫자들 읽기 
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	} 

	for(i=0; i<n-1; i++){
		
		idx = i; // i를 기준으로.  
		
		for(j = i+1; j<n; j++){
			
			if(a[j] < a[idx]) idx = j;  // 작은 값의 '인덱스'를 기억해둔다  
			
		}
		
		tmp = a[i];
		a[i] = a[idx];
		a[idx] = tmp;
		
	}

	for(i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	 
	return 0;
	
}

