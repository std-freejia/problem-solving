#include <stdio.h> 

// 18. ��������  noise_limit
/*
�� ������ ����ġ�� M���� ������ ����ȣ���� ���� �溸���� ������ ����Ϳ��� �︳�ϴ�. 
�� ������ N�� ������ �ǽð� ����ġ�� �־����� �ִ� �������� �溸���� �︰ �ð��� ���ϼ���. 

ù �ٿ� �ڿ��� N(10<=N<=100)�� M�� �־����ϴ�.
�� ��° �ٿ� N���� ������(1000���� �ڿ���)�� �� ������� �Էµȴ�.

�ִ� ���� �溸���� �︰ �ð�(��)�� ����ϼ���.
�溸���� ������ -1�� ����մϴ�.

input.txt
10 90
23 17 120 34 112 136 123 23 25 113 
*/

int main(int argc, char** argv) {

	int repeat = 0, i=0, limit = 0, temp = 0, count = 0, max = -2147000000;	
	//freopen("input.txt", "rt", stdin);	

	scanf("%d %d", &repeat, &limit);
	
	for(i=0; i<repeat; i++){
		scanf("%d", &temp);
		
		if(temp>limit){
			count++;
			if(count>max){
				max=count;
			}
		}else{
			count = 0;
		}
	}
	
	if(max==0) printf("-1\n");
	else printf("%d\n", max);
	
	return 0;
}


