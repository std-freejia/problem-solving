#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// 49. 블록의 최댓값   maximum_of_blocks

/*
 
현수에게 정면에서 본 단면과 오른쪽 측면에서 본 단면을 주고 최대 블록개수를 사용하여 정면과 오른쪽 측면에서 본 모습으로 블록을 쌓으라 했습니다.
현수가 블록을 쌓는데 사용해야 할 최대 개수를 출력하는 프로그램을 작성하세요.

정면에서의 높이 정보와 오른쪽 측면에서의 높이 정보가 주어지면 사용할 수 있는 블록의 쵀대 개수를 출력하세요.

▣ 입력설명
첫 줄에 블록의 크기 N(3<=N<=10)이 주어집니다. 블록이 크기는 정사각형 N*N입니다.
두 번째 줄에 N개의 정면에서의 높이 정보가 왼쪽 정보부터 주어집니다.
세 번째 줄에 N개의 오른쪽 측면 높이 정보가 앞쪽부터 주어집니다.
블록의 높이는 10 미만입니다.

▣ 출력설명
첫 줄에 블록의 최대 개수를 출력합니다.

*/


int main(int argc, char** argv){
	
	int i = 0, j = 0, size_of_block = 0, min = 0;

	//freopen("input.txt", "rt", stdin);

	scanf("%d", &size_of_block); // 입력받기 시작  
	
	vector<int> front(size_of_block), right(size_of_block);
	
	for(i=0; i<size_of_block; i++){
		scanf("%d", &front[i]);
	}

	for(i=size_of_block-1; i>=0; i--){
		scanf("%d", &right[i]);
	} // 입력 받기 끝.
	
	
	for(i=0; i<size_of_block; i++){
		
		for(j=0; j<size_of_block; j++){
			
			if(right[i] < front[j]){
				min += right[i];
			}else{
				min += front[j];
			}
		}
	} 
	
	printf("%d", min);
	
	return 0;
}


