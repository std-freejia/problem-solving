#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

// 43. ��������   

// ��  
int a[1001],  n;

int Count(int size){ // n
	int i, cnt=1, sum = 0; // �ݺ��� ����, dvd ����(�ּ� 1���ϱ�), ���� �� 
	
	for(i=1; i<=n; i++){ // ��� �� ��ȸ  
		if(sum + a[i] > size){
			cnt++;
			sum = a[i]; // �� dvd �� ��.  dvd�� �뷮���ٴ� �뷡�� �۾ƾ���. 
		}else{
			sum += a[i];
		}
	} 
	
	return cnt;
}
 
int main(int argc, char** argv){
	   
	//freopen("input.txt", "rt", stdin); 
	// max_value : ��� �߿� �ִ� ��.  
	int m, i, lt=1, rt=0, mid, res, max_value = -2147000000;
	
	scanf("%d %d", &n, &m);
	
	for(i=1; i<=n; i++){ // �ε��� 1 ���� �̿�  
		scanf("%d", &a[i]);
		rt = rt + a[i]; // ����� ��ü �� ������ ����  
		if(a[i]> max_value) max_value = a[i]; 
	}
	
	// �̺� �˻�
	while(lt <= rt){
		mid = (lt + rt)/2;  // dvd 1���� �ּ� �뷮 
		
		//mid ���� ������ �뷮���� Ȯ�� 
		// mid ���� ��� �뷡�� �� �뷮���ٴ� Ŀ�� �Ѵ�.  
		if(mid >= max_value && Count(mid) <= m){ // ���� �ȴ�  
			res = mid;
			rt = mid-1;
		}else{
			lt = mid+1;
		}
	} 
	
	printf("%d", res);
	
	return 0;
}

