#include <stdio.h> 
#include <string.h>
#include <vector> 
#include <algorithm>
using namespace std;

// 40. 교집합   intersection

/*

두 집합 A, B가 주어지면 두 집합의 교집합을 출력하는 프로그램을 작성하세요.

▣ 입력설명
첫 번째 줄에 집합 A의 크기 N(1<=N<=30,000)이 주어집니다.
두 번째 줄에 N개의 원소가 주어집니다. 원소가 중복되어 주어지지 않습니다.
세 번째 줄에 집합 B의 크기 M(1<=M<=30,000)이 주어집니다.
네 번째 줄에 M개의 원소가 주어집니다. 원소가 중복되어 주어지지 않습니다.
각 집합의 원소는 int형 변수의 크기를 넘지 않습니다.

▣ 출력설명
두 집합의 교집합을 오름차순 정렬하여 출력합니다

*/

int main(int argc, char** argv){
	
	int a_size, b_size, ap=0, bp=0, resp=0, i = 0; 
	
	freopen("input.txt", "rt", stdin);
	
	// 입력받기 시작  (벡터 3개 만들고 a와 b 입력받기) 
	scanf("%d", &a_size);
	vector<int> a(a_size);
	
	for(i=0; i<a_size; i++){
		scanf("%d", &a[i]);
	}
	
	scanf("%d", &b_size);
	vector<int> b(b_size);
	vector<int> res(a_size+b_size);
	
	for(i=0; i<b_size; i++){
		scanf("%d", &b[i]);
	} // 입력 받기 끝  
	
	sort(a.begin(), a.end()); // sort() 함수는 algorithm 헤더에 속함  
	sort(b.begin(), b.end()); 

	while(ap < a_size && bp < b_size){
		
		if(a[ap] == b[bp]){ // 교집합 발견 
			res[resp++] = a[ap++];
			bp++; 
		}else if(a[ap] < b[bp]){
			ap++;
		}else{ // a[ap] > b[bp] 
			bp++; 
		}
	}

	for(i=0; i<resp; i++){
		printf("%d ", res[i]);
	}

	return 0;
}

