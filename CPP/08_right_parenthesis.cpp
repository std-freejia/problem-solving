#include <stdio.h> 
using namespace std;

// 8. �ùٸ� ��ȣ  right_parenthesis
/*
��ȣ�� �ԷµǸ� �ùٸ� ��ȣ�̸� ��YES", �ùٸ��� ������ ��NO"�� ����մϴ�.
(())() �̰��� �ùٸ� ��ȣ��.  
(()()))�� �ùٸ� ��ȣ�� �ƴϴ�.
*/
int main(int argc, char** argv) {
	
	//freopen("input.txt", "rt", stdin);
	// (()) ����+1, ������ -1 �ϸ� ���� ������?  
	

	int i=0, num=0;
	char arr[31];

	scanf("%s", &arr);
	
	for(i=0; arr[i] != '\0'; i++){
		if('(' == arr[i]){
			num++;
		}else{
			num--;
		}
		
		if(num<0){ 
		// ������ �Ǵ� ����, ���°�ȣ���� �����ϴ� �̻��� ����. 
			break;
		}
	}
	
	if(num == 0){
		printf("YES\n");
	}else{ // ���� �� ��� ó��  
		printf("NO\n");
	}
	
	return 0;
}


