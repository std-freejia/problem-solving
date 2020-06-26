#include <stdio.h>
using namespace std;

// 62. �������� (��������) 
 
/*

���������� �ð����⵵�� ?   nlogN�� �ð����⵵�� ������.  


d(1,2) , d(3,4), d(5, 6)
2�� ������ ���� -> 2�� �� 
2�� ������ ���� -> 2�� �� 
...

d(1,4) d(5,8)
4�� ������ ���� - > 4�� �� 


d(1,8) 
8�� ������ ���� -> 8�� ��  

*/
 
int data[101], temp[101];
 
void divide(int left, int right){
	
	int mid = 0;
	int p1, p2, p3 = 0;  // �ε����� ����Ű�� ����Ʈ ����. (��ġ����) 
	int i = 0;
	
	if(left < right){
		
		mid = (left + right) / 2 ;
		
		divide(left, mid);
		divide(mid+1, right);
		
		// left~right ���� ������ ����.
		p1 = left;
		p2 = mid+1;
		p3 = left; // ���� ���� ����Ʈ  
	
		while(p1 <= mid && p2 <= right){ // ����  
			
			if(data[p1] < data[p2]) temp[p3++] = data[p1++];
			else temp[p3++] = data[p2++];
			
		}
		
		// ���� �� ó�� 
		while(p1 <= mid) temp[p3++] = data[p1++]; 
		while(p2 <= right) temp[p3++] = data[p2++];
		
		// temp -> data �� ���� 
		for(i = left; i<=right; i++){
			data[i] = temp[i];
		} 
		
	}else{
		
		return;
	}
	
} 
 
int main(void){

	//freopen("input.txt", "rt", stdin);
	
	int n, i = 0;
	
	scanf("%d", &n);
	
	for(i=1; i<=n; i++){ // �ε����� 1���� ���.  
		scanf("%d", &data[i]);
	} // �Է¹ޱ� ��. 
	
	divide(1, n); // ���� ��� �Լ�  
	
	for(i=1; i<=n; i++){ // ���� ��� ���  
		printf("%d ", data[i]);
	}
	
	return 0;
} 


