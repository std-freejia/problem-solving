#include <stdio.h> 
#include <vector> 
#include <algorithm>
using namespace std;

// 24.  Jolly Jumpers

/*
N���� ������ �̷���� ������ ���� ���� ������ �ִ� �� ���� ���� 1���� N-1������ ����
��� ������ �� ������ ������ ����(jolly jumper)��� �θ���. 

���� ��� ������ ���� �������� 1 4 2 3 �� �ڿ� �ִ� ���� ���� ���� ���� ���� 3 ,2, 1�̹Ƿ� 
�� ������ ������ ���۰� �ȴ�. 
� ������ ������ �������� �Ǵ��� �� �ִ� ���α׷��� �ۼ��϶�.

ù ��° �ٿ� �ڿ��� N(3<=N<=100)�� �־�����.
�� ���� �ٿ� N���� ������ �־�����. ������ ũ��� int �� �����ȿ� �ֽ��ϴ�.

������ �����̸� ��YES"�� ����ϰ�, �׷��� ������ ��NO"�� ����Ѵ�

input.txt
5
1 4 2 3 7

*/


int main(int argc, char** argv) {

	int total=0, i=0, pre=0, now=0, minus=0, absnum=0;
	bool flag = true;

	//freopen("input.txt", "rt", stdin);	

	scanf("%d", &total);
	
	vector<int> num(total);

	scanf("%d", &pre);

	for(i=1; i<total; i++){
		
		scanf("%d", &now);
		minus = abs(pre-now);
		
		if(minus > 0 && minus < total && num[minus] == 0){ // ���� �ȿ� �ִٸ�, �ߺ� üũ. 
			num[minus] = 1; 
		}else{ //
			printf("NO\n");
			return 0;
		}
		
		pre = now;
	}
	
	printf("YES\n");

	return 0;
}

