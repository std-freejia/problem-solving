#include <stdio.h>
#include <algorithm>
#include <stack>
#include <vector> 
using namespace std;

// 55. ��������  train_stack  (��������� �߿��ѹ���)

/*

P (push) ������ �����ο� �ִ´�. 
O (out) �ֻ�� ������ B���÷� ������. 
				
* �Է¼��� 
ù ��° �ٿ� �ڿ��� N(3<=N<=30)�� �־�����.
�� ��° �ٿ� A���ÿ��� ����ϴ� ������ȣ���� ���ʴ�� �Էµȴ�.

* ��¼���
������ �۾��� ������� P�� O�� ����Ѵ�.

*/

int main(int argc, char** argv){
	
	//freopen("input.txt", "rt", stdin);
	
	stack<int> s; 
	int i, j=1; 
	int n, m = 0;
	
	// P, O ������ ����
	vector<char> str;
	 
	scanf("%d", &n);
	
	for(i=1; i<=n; i++){
		scanf("%d", &m);
		
		s.push(m);
		str.push_back('P'); 
		
		while(1){
			
			if(s.empty()) break;
			
			if(j == s.top()){
				s.pop();
				j++;
				str.push_back('O'); 

			}else{
				break;
			}
		}
		
	}
	
	if(!s.empty()){
		printf("impossible\n");
	}else{ 
		for(i=0; i<str.size(); i++){
			printf("%c", str[i]);
		}
	}
	
	return 0;
} 
