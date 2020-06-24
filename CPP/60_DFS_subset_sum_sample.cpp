#include <stdio.h>
#include <algorithm>
#include <vector> 
using namespace std;

// 60. ���� ���� �κ����� (DFS �Ƹ������ͺ�) 


// ������ �ڵ� 

/* ������ �ڵ� ����  
 
�ϳ��� �κ������� ���� ����, ������ �ֵ��� ���ϳ��� �κ������� �ȴ�. 
�ϴ� ��� ����� ���� total ������ �����Ѵ�. 
�ϳ��� �κ������� ����� ���� ���ϰ�, �� ���� total���� ����.  �� ���� ������ "YES"  

*/

int n, a[11], total = 0; 
bool flag_end = false;

void DFS(int length, int sum){

	if(length == n+1){
		// ���� ���غ���. 
		if((total-sum) == sum){ // �κ������� �հ�, ������������ ���� ��  
			flag_end = true;
		}
		return; 
	
	}else{
	
		DFS(length+1, sum + a[length]); // ���� �ε��� ���Ҹ� ���տ��ҷ� �����. 
		DFS(length+1, sum);  // ���� �ε��� ���Ҹ� ���տ��ҷ� ��� ����. (���� ���ϰ� ������) 

	}
		
}

int main(void){
	
	//freopen("input.txt", "rt", stdin);
	
	int i = 0;
	
	scanf("%d", &n); // ����� ���� 
	
	for(i=1; i<=n; i++){
		scanf("%d", &a[i]);
		total += a[i]; // ��� ����� ��  
	} 
	
	DFS(1, 0); // ù��° ��Һ��� �̿��Ѵ�. ���� ���տ��� ����� �� ������Ŵ. 
	
	if(flag_end){
		printf("YES");
	} else{
		printf("NO");
	}
	return 0;
} 


