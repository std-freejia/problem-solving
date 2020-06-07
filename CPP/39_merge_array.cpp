#include <stdio.h> 
#include <string.h>
#include <vector> 
#include <algorithm>
using namespace std;

// 39. 두 배열 합치기  merge_array

/*
오름차순으로 정렬이 된 두 배열이 주어지면 두 배열을 오름차순으로 합쳐 출력하는 프로그램을 작성하세요.

▣ 입력설명
첫 번째 줄에 첫 번째 배열의 크기 N(1<=N<=100)이 주어집니다.
두 번째 줄에 N개의 배열 원소가 오름차순으로 주어집니다.
세 번째 줄에 두 번째 배열의 크기 M(1<=M<=100)이 주어집니다.
네 번째 줄에 M개의 배열 원소가 오름차순으로 주어집니다.
각 배열의 원소는 int형 변수의 크기를 넘지 않습니다.

▣ 출력설명
오름차순으로 정렬된 배열을 출력합니다.

*/


int arr_a[101], arr_b[101], res[300];

int main(int argc, char** argv){
	
	// 배열의 크기 저장, 인덱스를 저장하는 변수 3개 (p) 셋 다 1로 시작함.  
	int a_size, b_size, arr_size, i, p1=1, p2=1, p3=1; 
	
	//freopen("input.txt", "rt", stdin);
	
	// 필요한 배열 3개 : 입력받는 배열 arr_a, arr_b, 결과배열 res 
	 
	// 입력받기 시작  
	scanf("%d", &a_size);
	//vector<int> arr_a(a_size);
		
	for(i=1; i<=a_size; i++){  // 벡터에 숫자를 입력받는 인덱스를  1 부터 하고 있음.  
		scanf("%d", &arr_a[i]);
	}
	
	scanf("%d", &b_size);
	//vector<int> arr_b(b_size);
		
	for(i=1; i<=b_size; i++){ 
		scanf("%d", &arr_b[i]);
	}// 입력받기 끝  
	
	// 결과 저장할 벡터  
	//vector<int> res(a_size+b_size);

	// 인덱스 변수 2개를 가지고 작은 수가 나올 때 마다 p1 또는 p2를 이동시킴. 
	while(p1 <= a_size && p2 <= b_size){ // 어느 한 쪽이 자기 크기보다 커질 때까지. 
		
		if(arr_a[p1] < arr_b[p2]){
			res[p3++] = arr_a[p1++]; 
			// p3를 대입한 후에, 1증가 해준다. res[p3]; p3+=1; 과 같다.  
		}else{
			res[p3++] = arr_b[p2++]; 
		}
	}
	
	// 한 쪽은 다 res에 들어가고, 다른 한 쪽은 res에 못들어가고 남았을 것. 
	while(p1 <= a_size) res[p3++] = arr_a[p1++];
	while(p2 <= b_size) res[p3++] = arr_b[p2++];

	for(i=1; i<=a_size+b_size; i++){ // 출력 할 때도 인덱스 1부터 시작. 
		printf("%d ", res[i]);
	}
	
	return 0;
}

