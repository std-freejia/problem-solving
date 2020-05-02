#include <stdio.h> 
using namespace std;

// 8. 올바른 괄호  right_parenthesis
/*
괄호가 입력되면 올바른 괄호이면 “YES", 올바르지 않으면 ”NO"를 출력합니다.
(())() 이것은 올바른 괄호다.  
(()()))은 올바른 괄호가 아니다.
*/
int main(int argc, char** argv) {
	
	//freopen("input.txt", "rt", stdin);
	// (()) 열면+1, 닫으면 -1 하면 되지 않을까?  
	

	int i=0, num=0;
	char arr[31];

	scanf("%s", &arr);
	
	for(i=0; arr[i] != '\0'; i++){
		if('(' == arr[i]){
			num++;
		}else{
			num--;
		}
		
		if(num<0){ 
		// 음수가 되는 순간, 여는괄호부터 시작하는 이상한 순간. 
			break;
		}
	}
	
	if(num == 0){
		printf("YES\n");
	}else{ // 음수 및 양수 처리  
		printf("NO\n");
	}
	
	return 0;
}


