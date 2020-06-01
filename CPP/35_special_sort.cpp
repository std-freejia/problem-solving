#include <stdio.h> 
#include <vector> 
#include <algorithm>
using namespace std;


// 35. Special Sort (구글 인터뷰) 

/*

N개의 정수가 입력되면 당신은 입력된 값을 정렬해야 한다.
음의 정수는 앞쪽에 양의정수는 뒷쪽에 있어야 한다. 
또한 양의정수와 음의정수의 순서에는 변함이 없어야 한다.

첫 번째 줄에 정수 N(5<=N<=100)이 주어지고, 그 다음 줄부터 음수를 포함한 정수가 주어진다. 
숫자 0은 입력되지 않는다.

정렬된 결과를 출력한다


입력예제 1 
8
1 2 3 -3 -2 5 6 -6

출력예제 1
-3 -2 -6 1 2 3 5 6

*/


int main(int argc, char** argv) {

	// 요소 배열, 자료 개수, 반복문에 필요한 변수들.  
	int arr[101], num=0, i=0, j=0, temp; 
	
	//freopen("input.txt", "rt", stdin);
	
	scanf("%d", &num);
	
	// 숫자들 읽기 
	for(i=0; i<num; i++){
		scanf("%d", &arr[i]);
	} 

	for(i=0; i<num-1; i++ ){ 
		
		for(j=0; j<num-i-1; j++){
			
			if(arr[j] > 0 && arr[j+1] < 0){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
    
	for(i=0; i<num; i++){
		printf("%d ", arr[i]);
	} 
		 
	return 0;
	
}

/*
삽입정렬보다는 버블정렬이 적합하다. 
왜냐하면 "양의정수와 음의정수의 순서"를 유지해야 하기 때문이다.  

앞이 양수, 뒤가 음수인 경우만 버블정렬로 Swap 한다.  

*/
