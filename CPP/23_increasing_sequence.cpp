#include <stdio.h> 
#include <vector> 

// 23. ���� �κ� ��������   increasing_sequence 

/*
N���� ���ڰ� ������ ������ �־����ϴ�. 
�� ���� �� ���������� �����ϴ� �κ� ������ �ִ���̸� ���Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
���� N=9�̰�
5 7 3 3 12 12 13 10 11 �̸� ��3 3 12 12 13���κ��� �ִ� ���� ���������̹Ƿ� �� ������
5�� ����մϴ�. 
���� ���� ���� �����ϴ� �ɷ� �����մϴ�.

input.txt
9
5 7 3 3 12 12 13 10 11

*/


int main(int argc, char** argv) {

	int i=0, count=0, length=1, max=-2147000000;
	
	//freopen("input.txt", "rt", stdin);	

	scanf("%d", &count);
	
	// �迭 ���� �Ҵ�  
	std::vector<int> num(count);
	
	for(i=0; i<count; i++){
		scanf("%d", &num[i]);
	}
		
	for(i=1; i<count; i++){
		
		if(num[i-1] <= num[i]){ //�������� ���ų� ũ�� length++
			length++;
			
			if (max < length){ // max�� ��� ����  
				max = length;
			}
		}else{ // �ƴϴ� length = 0 
			length = 1;
		}
		//printf("%d %d, length:%d\n", num[i-1], num[i], length);
	}
	
	printf("%d", max);

	return 0;
}

