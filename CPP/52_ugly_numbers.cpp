#include <stdio.h>
#include <algorithm>
#include <stack>
using namespace std;

// 52. Ugly Numbers (������Ʈ �˰��� ����) 

/*
� ���� ���μ����� ���� �� �� ���μ��� 2 �Ǵ� 3 �Ǵ� 5�θ� �̷���� ���� Ugly Number��� �θ��ϴ�. 
Ugly Number�� ���ʴ�� ����� 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, .......�Դϴ�. 
���� 1�� Ugly Number�� ù ��° ���� �մϴ�. 
�ڿ��� N�� �־����� Ugly Number�� ���ʷ� ���� �� N��° Ugly Number�� ���ϴ� ���α׷��� �ۼ��ϼ���.

�� �Է¼���
ù �ٿ� �ڿ��� N(3<=N<=1500)�� �־����ϴ�.

�� ��¼���
ù �ٿ� N��° Ugly Number�� ����ϼ���.

*/


int a[1501];

int main(int argc, char** argv){
	
	//freopen("input.txt", "rt", stdin);

	int num, i = 0;
	int min = 2147000000;
	int p2, p3, p5; // �ε����� ����Ű�� ����Ʈ ����
	
	scanf("%d", &num);
	
	a[1] = 1;
	p2=p3=p5=1; // 1�� ����  
	
	for(i=2; i<=num; i++){
		
		// p2, p3, p5 �߿��� �ּҰ� ����  
		if(a[p2] * 2 < a[p3] * 3) min = a[p2] * 2;
		else min = a[p3] * 3;
		if(a[p5] * 5 < min) min = a[p5] * 5;
		
		// �ּҰ��� 2���� ��츦 ó���Ѵ�. (2���̸� 2���� ����Ʈ ���� ��� ++) 
		if(a[p2] * 2 == min) p2++;
		if(a[p3] * 3 == min) p3++;  
		if(a[p5] * 5 == min) p5++; 
		
		a[i] = min;
	}
	
	printf("%d", a[num]);
	
	return 0;
} 
