#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

// 45. ���ֱ��ϱ� (�����۽�)  save_princess

/*

N���� �����߿� ���ָ� ���Ϸ� �� ���ڸ� ���� �Ѵ�. 
���� ���ڵ��� ���� ������ 1������ N������ ���ʷ� ��ȣ�� �ű��. 
�׸��� 1�� ���ں��� N�� ���ڱ��� ������� �ð� �������� ���ư��� ���׶��� �ɰ� �Ѵ�. 
�׸��� 1�� ���ں��� �ð�������� ���ư��� 1���� �����Ͽ� ��ȣ�� ��ġ�� �Ѵ�. 
�� ���ڰ� K(Ư������)�� ��ġ�� �� ���ڴ� ���ָ� ���Ϸ� ���µ��� ���ܵǰ� �� ������ ������ �ȴ�. �׸��� ���� ���ں��� �ٽ� 1���� �����Ͽ� ��ȣ�� ��ģ��.
�̷��� �ؼ� ���������� ���� ���ڰ� ���ָ� ���Ϸ� �� �� �ִ�.
 
���� ��� �� 8���� ���ڰ� �ְ�, 3�� ��ģ ���ڰ� ���ܵȴٰ� ����. 
ó������ 3�� ���ڰ� 3�� ���� ���ܵȴ�. 
�̾� 6, 1, 5, 2, 8, 4�� ���ڰ� ���ʴ�� ���ܵǰ� ���������� ���� �� 7�� ���ڿ��� ���ָ� ���Ϸ����ϴ�.
N�� K�� �־��� �� ���ָ� ���Ϸ� �� ������ ��ȣ�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
 
�� �Է¼���
ù �ٿ� �ڿ��� N(5<=N<=1,000)�� K(2<=K<=9)�� �־�����.
8 3

�� ��¼���
ù �ٿ� ������ ���� ������ ��ȣ�� ����մϴ�.
7

*/

int main(int argc, char** argv){
	
	int prince = 0, limit = 0, pos = 0, i = 0, bp = 0, cnt=0;
	//freopen("input.txt", "rt", stdin);
	scanf("%d %d", &prince, &limit);

	vector<int> arr(prince+1);
	
	while(bp != prince-1){
		pos++;
		
		if(pos > prince){
			pos = 1;
		}
		
		if(arr[pos] == 0){
			cnt++;
			
			if(cnt == limit){ // Ư�� ��°�� ���ڸ� �ƿ���Ŵ.  
				arr[pos] = 1;
				cnt = 0;
				bp++; // �ƿ���Ų ������ ������ ����.  
			}
		}
	} 
	
	for(i=1; i<=prince; i++){
		if(arr[i] == 0){
			printf("%d", i);
			break;
		}
	}
	
	return 0;
}

/*
  
�ε����� 1���� �̿��ϱ� ���� ���͸� n+1 ũ��� ����. 
0�� ������ k ��° ���� ����.  cnt ������ ����. 
k��° ������ ���� 1�� �����Ѵ�. 
break point �� n-1 �� �Ǹ� while������ Ż���Ѵ�.  

�ε��� 1 ���� prince ���� ��ȸ�ϸ鼭 ���� 0���� ������ �ε����� ã�Ƽ� ����Ѵ�.  
*/