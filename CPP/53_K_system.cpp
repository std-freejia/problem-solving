#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

// 53. K진수  

/*
10진수 N이 입력되면 K진수로 변환하여 출력하는 프로그램을 작성하세요. 
스택 자료구조를 사용하시기 바랍니다.

▣ 입력설명
첫 번째 줄에 10진수 N(10<=N<=1,000)과 K(2, 5, 8, 16)가 주어진다.

▣ 출력설명
K진수를 출력한다.

*/

int arr[100];
int top_idx = -1;

void Push(int input){
	arr[++top_idx] = input;
}

int Pop(void){
	return arr[top_idx--];	
}

int main(int argc, char** argv){

	int input, system = 0;
	int i = 0;	 
	char str[20] = "0123456789ABCDEF"; // 2, 8, 10, 16 진수 
	 
	//freopen("input.txt", "rt", stdin);
	
	scanf("%d %d", &input, &system);
	
	while(input > 0){ // system 진수로 변환  
		
		Push(input%system);
		input /= system;
		
	}
	
	while(top_idx != -1){
		printf("%c", str[Pop()]);
	}
	
	return 0;
	
}

/*
처음에 풀었을 때, 테스트케이스 5개중에 2개가 시간 초과가 났다.  
그리고 출력할 때 top_idx가 -1이 될 때까지 Pop()을 해야되는 부분이 틀렸었다.  

*/


/*  <stack> 이용하여 푼 코드 

#include <stdio.h>
#include <algorithm>
#include <stack>
using namespace std;


int main(int argc, char** argv){

	int input, system = 0;
	int i = 0;	 
	char str[20] = "0123456789ABCDEF"; // 2, 8, 10, 16 진수 
	stack<int> s;
	freopen("input.txt", "rt", stdin);
	
	scanf("%d %d", &input, &system);
	
	while(input > 0){ // system 진수로 변환  
		
		s.push(input%system);
		input /= system;
		
	}
	
	while(!s.empty()){
		printf("%c", str[s.top()]); // 스택의 맨 위의 자료를 참조. 
		s.pop(); // 실제 pop 하여 제거.  
	}
	
	return 0;
	
}


*/
