#include <stdio.h>
#include <algorithm>
#include <stack>
#include <vector> 
using namespace std;

// 58. ����Ʈ�� ���̿켱Ž��(DFS)

/*
������ȸ, ������ȸ�� �����غ���.  
�ݵ�� ���̿� �׷�����. 
������ȸ�� Ư�� �߿��ϴ�.  

*/
 
void DFS(int vertex){ // ������ ��ȸ�Ѵ�. ������ȸ.   
	
	if(vertex > 7){ // ����  
		return;
	}else{
		
		printf("%d ", vertex); // ������ȸ  		
		DFS(vertex * 2); // ���� �ڽ��� *2 	
		DFS(vertex * 2 + 1); // ������ �ڽ��� *2 + 1  
		
	}
}
/*
void DFS(int vertex){ // ������ȸ  
	
	if(vertex > 7){ 
		return;
	}else{		
		DFS(vertex * 2); 	
		DFS(vertex * 2 + 1); 
		printf("%d ", vertex); // ������ȸ  
	}
}
*/

int main(int argc, char** argv){
	
	DFS(1);
	
	return 0;
} 
