#include <stdio.h> 

// 17. ������ ���� sum_quiz  
/*
�������� �� �л��鿡�� ���ڰ� ���� ī�带 ����ϴ�. 
�� �л����� 1���� �ڱ� ī�忡 ���� ���ڱ����� ���� ���ϴ� �����Դϴ�. 

ù �ٿ� �� �л����� �ڿ��� N(1<=N<=10)�� �־����ϴ�.
�� �л����� 1���� N���� ��ȣ�� �ο��Ǿ� �ִٰ� �����մϴ�.
�� ��° �ٺ��� 1�� �л������� ī�忡 ���� ���� �л��� ���� ������ ������ ���̿� �ΰ� �Էµȴ�. 
ī�忡 ���� ���� 1000�� ���� �ʴ´�.

ù �ٺ��� 1�� �л��� ������ ���߸� ��YES", Ʋ���� ��NO"�� ����ϼ���.

input.txt
3
10 55
20 350
100 5050
*/

int main(int argc, char** argv) {

	int repeat = 0, i=0, j=0, sum=0, num=0, answer=0;	
	//freopen("input.txt", "rt", stdin);	

	scanf("%d", &repeat);
	
	for(i=0; i<repeat; i++){
		
		scanf("%d %d", &num, &answer);
		
		sum = 0;

		for(j=1; j<=num; j++){
			sum += j;	
		}
		
		if(answer == sum) printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}


