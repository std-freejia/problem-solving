#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

// 42. 이분검색  binary_search

/*
임의의 N개의 숫자가 입력으로 주어집니다. 
N개의 수를 오름차순으로 정렬한 다음 N개의 수 중 한 개의 수인 M이 주어지면 이분검색으로 M이 정렬된 상태에서 몇 번째에 있는지 구하는
프로그램을 작성하세요.

▣ 입력설명
첫 줄에 한 줄에 자연수 N(3<=N<=1,000,000)과 M이 주어집니다.
두 번째 줄에 N개의 수가 공백을 사이에 두고 주어집니다.
8 32
23 87 65 12 57 32 99 81

▣ 출력설명
첫 줄에 정렬 후 M의 값의 위치 번호를 출력합니다. 
(주의. 몇 번째인지 출력이므로 0이 아니라 1번째 부터 세야 한다.) 
3
 
*/


int main(int argc, char** argv){
	
	// 입력받은 숫자 받을 변수, 왼쪽 오른쪽 중간 인덱스 변수  
	int cnt = 0, target = 0, temp = 0,i=0, lp=0, rp=0, cp=0;
	
	//freopen("input.txt", "rt", stdin);
	
	scanf("%d %d", &cnt, &target);
		
	// 벡터의 push_back() 사용  
	vector<int> arr;
	
	for(i=0; i<cnt; i++){
		scanf("%d", &temp);
		arr.push_back(temp);
	} 
	
//	vector<int> arr(cnt);
//	for(i=0; i<cnt; i++){
//		scanf("%d", &arr[i]);
//	} 
	
	// 정렬 
	sort(arr.begin(), arr.end());
	
	rp = cnt-1;

	while(lp<=rp){
		cp = (lp+rp)/2;
		
		if(arr[cp] == target){// 찾음  
			printf("%d", cp+1);
			break;
		}else if(arr[cp] < target){
			lp = cp+1;
		}else if(arr[cp] > target){
			rp = cp-1;
		}
	}
	
	return 0;	
} 

