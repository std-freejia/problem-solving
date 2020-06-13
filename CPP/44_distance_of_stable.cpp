#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

// 44. ������ ���ϱ�  distance_of_stable

int Count(int mid, vector<int> stable, int cnt_stable){
	
	// �� �ϳ��� ù �������� �ΰ� �����Ѵ�.  
	int i = 0, cnt = 1, pos = stable[1];
		
	for(i=2; i<= cnt_stable; i++){
		
		if(mid <= stable[i] - pos){ // �� �������� ������ mid �Ÿ� �̻��� ���.  
			cnt++;
			pos = stable[i];
		}
	}
	
	return cnt;
}

int main(int argc, char** argv){
	
	// ������ ����, ���� ����, �ݺ��� ����  
	int cnt_stable = 0, horse = 0, i = 0;
	int lp = 1, rp = 0, mid = 0, res = 0;
	
	//freopen("input.txt", "rt", stdin);
	
	scanf("%d %d", &cnt_stable, &horse);
	
	vector<int> stable(cnt_stable + 1); // �ε��� 1 ���� ���  
	
	for(i=1; i <= cnt_stable; i++){ // �ε��� 1 ���� ���  
		scanf("%d", &stable[i]);
	}

	// ���� 
	sort(stable.begin(), stable.end());
	 
	rp = stable[cnt_stable];
	
	while(lp <= rp){ // �̺�Ž��  
		
		mid = (lp + rp)/2;
		
		if(Count(mid, stable, cnt_stable) >= horse){
			res = mid;
			lp = mid + 1; // �� �ָ� ����߷�����.  
		}else{
			rp = mid - 1;
		}
	}
	
	printf("%d", res);
	
	return 0;
}


/* �� ������ ���� �˰������� Ǭ��.  

N���� �������� 1���� �������� �ֽ��ϴ�. 
�� �������� x1, x2, x3, ......, xN�� ��ǥ�� ��
����, ���������� ��ǥ�� �ߺ��Ǵ� ���� �����ϴ�.
������ C������ ���� ������ �ִµ�, �� ������ ���� ������ �ִ� ���� �������� �ʽ��ϴ�.
�� ���������� �� ������ ���� ���� �� �ְ�, ���� ����� �� ���� �Ÿ��� �ִ밡 �ǰ� ���� �������� ��ġ�ϰ� �ͽ��ϴ�.
C������ ���� N���� �������� ��ġ���� �� ���� ����� �� ���� �Ÿ��� �ִ밡 �Ǵ� �� �ִ밪�� ����ϴ� ���α׷��� �ۼ��ϼ���.

�� �Է¼���
ù �ٿ� �ڿ��� N(3<=N<=200,000)�� C(2<=C<=N)�� ������ ���̿� �ΰ� �־����ϴ�.
��° �ٺ��� N���� �ٿ� ���� �������� ��ǥ xi(0<=xi<=1,000,000,000)�� �� �ٿ� �ϳ��� �־����ϴ�.

�� ��¼���
ù �ٿ� ���� ����� �� ���� �ִ� �Ÿ��� ����ϼ���.

*/
