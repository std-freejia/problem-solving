#include <stdio.h>
#include <algorithm>
#include <stack>
using namespace std;

// 54. �ùٸ� ��ȣ (���� �ڷᱸ�� Ȱ�� �߿� ���� )
// exact_parenthesis 

 
int main(int argc, char** argv){
	
	//freopen("input.txt", "rt", stdin);
	stack<char> st;
	char arr[31]; // ��ȣ ���ڿ� �о���� �迭. N ������ 30 �̹Ƿ�. 
	int i = 0;
	int flag = 1; //flag 1: ���ڿ��� ������ ����.  
				  //flag 0:  ')' ���� �����ؼ� �ߴ�. 
	 
	scanf("%s", &arr);
	
	for(i=0; arr[i] != '\0'; i++){ // ���ڿ��� �о���δ�  
		
		if(arr[i] == '('){ // Push 
			st.push(arr[i]); 
			
		}else{ // ')' �ݴ� ��ȣ  
			
			if(st.empty()){ // ����ִ� ������� Ȯ���ϱ�  
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
