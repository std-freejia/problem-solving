#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

// 42. �̺а˻�  binary_search

/*
������ N���� ���ڰ� �Է����� �־����ϴ�. 
N���� ���� ������������ ������ ���� N���� �� �� �� ���� ���� M�� �־����� �̺а˻����� M�� ���ĵ� ���¿��� �� ��°�� �ִ��� ���ϴ�
���α׷��� �ۼ��ϼ���.

�� �Է¼���
ù �ٿ� �� �ٿ� �ڿ��� N(3<=N<=1,000,000)�� M�� �־����ϴ�.
�� ��° �ٿ� N���� ���� ������ ���̿� �ΰ� �־����ϴ�.
8 32
23 87 65 12 57 32 99 81

�� ��¼���
ù �ٿ� ���� �� M�� ���� ��ġ ��ȣ�� ����մϴ�. 
(����. �� ��°���� ����̹Ƿ� 0�� �ƴ϶� 1��° ���� ���� �Ѵ�.) 
3
 
*/


int main(int argc, char** argv){
	
	// �Է¹��� ���� ���� ����, ���� ������ �߰� �ε��� ����  
	int cnt = 0, target = 0, temp = 0,i=0, lp=0, rp=0, cp=0;
	
	//freopen("input.txt", "rt", stdin);
	
	scanf("%d %d", &cnt, &target);
		
	// ������ push_back() ���  
	vector<int> arr;
	
	for(i=0; i<cnt; i++){
		scanf("%d", &temp);
		arr.push_back(temp);
	} 
	
//	vector<int> arr(cnt);
//	for(i=0; i<cnt; i++){
//		scanf("%d", &arr[i]);
//	} 
	
	// ���� 
	sort(arr.begin(), arr.end());
	
	rp = cnt-1;

	while(lp<=rp){
		cp = (lp+rp)/2;
		
		if(arr[cp] == target){// ã��  
			printf("%d", cp+1);
			break;
		}else if(arr[cp] < target){
			lp = cp+1;
		}else if(arr[cp] > target){
			rp = cp-1;
		}
	}
	
	return 0;	
} 

