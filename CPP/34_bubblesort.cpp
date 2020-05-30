#include <stdio.h> 
#include <vector> 
#include <algorithm>
using namespace std;


// 34. 버블정렬  

/*
N개이 숫자가 입력되면 오름차순으로 정렬하여 출력하는 프로그램을 작성하세요.
정렬하는 방법은 버블정렬입니다.

첫 번째 줄에 자연수 N(1<=N<=100)이 주어집니다.
두 번째 줄에 N개의 자연수가 공백을 사이에 두고 입력됩니다. 각 자연수는 정수형 범위 안에
있습니다. 

입력
6
13 23 11 7 5 15

출력
5 7 11 13 15 23

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

    for(i=0; i<num-1; i++){ // num-1 만큼 순회  
        
        for(j=0; j<num-(i+1); j++){ // 정렬할 요소가 1개씩 줄어든다 
            
            if(arr[j] > arr[j+1]){ // 교환 조건
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

