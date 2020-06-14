#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

// 45. 공주구하기 (조세퍼스)  save_princess

/*

N명의 왕자중에 공주를 구하러 갈 왕자를 골라야 한다. 
왕은 왕자들을 나이 순으로 1번부터 N번까지 차례로 번호를 매긴다. 
그리고 1번 왕자부터 N번 왕자까지 순서대로 시계 방향으로 돌아가며 동그랗게 앉게 한다. 
그리고 1번 왕자부터 시계방향으로 돌아가며 1부터 시작하여 번호를 외치게 한다. 
한 왕자가 K(특정숫자)를 외치면 그 왕자는 공주를 구하러 가는데서 제외되고 원 밖으로 나오게 된다. 그리고 다음 왕자부터 다시 1부터 시작하여 번호를 외친다.
이렇게 해서 마지막까지 남은 왕자가 공주를 구하러 갈 수 있다.
 
예를 들어 총 8명의 왕자가 있고, 3을 외친 왕자가 제외된다고 하자. 
처음에는 3번 왕자가 3을 외쳐 제외된다. 
이어 6, 1, 5, 2, 8, 4번 왕자가 차례대로 제외되고 마지막까지 남게 된 7번 왕자에게 공주를 구하러갑니다.
N과 K가 주어질 때 공주를 구하러 갈 왕자의 번호를 출력하는 프로그램을 작성하시오.
 
▣ 입력설명
첫 줄에 자연수 N(5<=N<=1,000)과 K(2<=K<=9)가 주어진다.
8 3

▣ 출력설명
첫 줄에 마지막 남은 왕자의 번호를 출력합니다.
7

*/

int main(int argc, char** argv){
	
	int prince = 0, limit = 0, pos = 0, i = 0, bp = 0, cnt=0;
	//freopen("input.txt", "rt", stdin);
	scanf("%d %d", &prince, &limit);

	vector<int> arr(prince+1);
	
	while(bp != prince-1){
		pos++;
		
		if(pos > prince){
			pos = 1;
		}
		
		if(arr[pos] == 0){
			cnt++;
			
			if(cnt == limit){ // 특정 번째의 왕자를 아웃시킴.  
				arr[pos] = 1;
				cnt = 0;
				bp++; // 아웃시킨 왕자의 개수를 센다.  
			}
		}
	} 
	
	for(i=1; i<=prince; i++){
		if(arr[i] == 0){
			printf("%d", i);
			break;
		}
	}
	
	return 0;
}

/*
  
인덱스를 1부터 이용하기 위해 벡터를 n+1 크기로 생성. 
0의 개수를 k 번째 까지 센다.  cnt 변수에 누적. 
k번째 왕자의 값을 1로 변경한다. 
break point 가 n-1 이 되면 while문에서 탈출한다.  

인덱스 1 부터 prince 까지 순회하면서 값이 0으로 남겨진 인덱스를 찾아서 출력한다.  
*/
