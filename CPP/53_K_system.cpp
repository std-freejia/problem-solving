#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

// 53. K����  

/*
10���� N�� �ԷµǸ� K������ ��ȯ�Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���. 
���� �ڷᱸ���� ����Ͻñ� �ٶ��ϴ�.

�� �Է¼���
ù ��° �ٿ� 10���� N(10<=N<=1,000)�� K(2, 5, 8, 16)�� �־�����.

�� ��¼���
K������ ����Ѵ�.

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
	char str[20] = "0123456789ABCDEF"; // 2, 8, 10, 16 ���� 
	 
	//freopen("input.txt", "rt", stdin);
	
	scanf("%d %d", &input, &system);
	
	while(input > 0){ // system ������ ��ȯ  
		
		Push(input%system);
		input /= system;
		
	}
	
	while(top_idx != -1){
		printf("%c", str[Pop()]);
	}
	
	return 0;
	
}

/*
ó���� Ǯ���� ��, �׽�Ʈ���̽� 5���߿� 2���� �ð� �ʰ��� ����.  
�׸��� ����� �� top_idx�� -1�� �� ������ Pop()�� �ؾߵǴ� �κ��� Ʋ�Ⱦ���.  

*/


/*  <stack> �̿��Ͽ� Ǭ �ڵ� 

#include <stdio.h>
#include <algorithm>
#include <stack>
using namespace std;


int main(int argc, char** argv){

	int input, system = 0;
	int i = 0;	 
	char str[20] = "0123456789ABCDEF"; // 2, 8, 10, 16 ���� 
	stack<int> s;
	freopen("input.txt", "rt", stdin);
	
	scanf("%d %d", &input, &system);
	
	while(input > 0){ // system ������ ��ȯ  
		
		s.push(input%system);
		input /= system;
		
	}
	
	while(!s.empty()){
		printf("%c", str[s.top()]); // ������ �� ���� �ڷḦ ����. 
		s.pop(); // ���� pop �Ͽ� ����.  
	}
	
	return 0;
	
}


*/
