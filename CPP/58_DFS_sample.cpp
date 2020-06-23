#include <stdio.h>
#include <algorithm>
#include <stack>
#include <vector> 
using namespace std;

// 58. 이진트리 깊이우선탐색(DFS)

/*
전위순회, 후위순회를 연습해보자.  
반드시 종이에 그려보자. 
후위순회가 특히 중요하다.  

*/
 
void DFS(int vertex){ // 정점을 순회한다. 전위순회.   
	
	if(vertex > 7){ // 종료  
		return;
	}else{
		
		printf("%d ", vertex); // 전위순회  		
		DFS(vertex * 2); // 왼쪽 자식은 *2 	
		DFS(vertex * 2 + 1); // 오른쪽 자식은 *2 + 1  
		
	}
}
/*
void DFS(int vertex){ // 후위순회  
	
	if(vertex > 7){ 
		return;
	}else{		
		DFS(vertex * 2); 	
		DFS(vertex * 2 + 1); 
		printf("%d ", vertex); // 후위순회  
	}
}
*/

int main(int argc, char** argv){
	
	DFS(1);
	
	return 0;
} 
