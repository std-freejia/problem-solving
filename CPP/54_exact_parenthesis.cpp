#include <stdio.h>
#include <algorithm>
#include <stack>
using namespace std;

// 54. 올바른 괄호 (스택 자료구조 활용 중요 문제 )
// exact_parenthesis 

 
int main(int argc, char** argv){
	
	//freopen("input.txt", "rt", stdin);
	stack<char> st;
	char arr[31]; // 괄호 문자열 읽어들일 배열. N 제한이 30 이므로. 
	int i = 0;
	int flag = 1; //flag 1: 문자열을 끝까지 읽음.  
				  //flag 0:  ')' 개수 부족해서 중단. 
	 
	scanf("%s", &arr);
	
	for(i=0; arr[i] != '\0'; i++){ // 문자열을 읽어들인다  
		
		if(arr[i] == '('){ // Push 
			st.push(arr[i]); 
			
		}else{ // ')' 닫는 괄호  
			
			if(st.empty()){ // 비어있는 경우인지 확인하기  
				printf("NO");
				flag = 0;
				break;
			}else{
				st.pop();
			}
		}
	}
	
	if(st.empty() && flag == 1){ 
		printf("YES");
	}else if(!st.empty() && flag == 1){
		printf("NO");
	}
	
	return 0;
} 
