#include <stdio.h> 
using namespace std;

// 7. ���� �ܾ� ���� recovery_voca
// ����ܾ ������ ǥ����� ������ �����ϰ� �ҹ���ȭ ���� ����ϴ� ���α׷��� �ۼ��ϼ���.

int main(int argc, char** argv) {
	
	//freopen("input.txt", "rt", stdin);
	char input[101], res[101];
	int i, pos=0;
	
	//�ٹٲޱ��� ���ڷ� �о�� �ϴϱ� ������ �д� gets() �̿�
	gets(input);
	
	for(i=0; input[i]!='\0'; i++){
		if(input[i] != ' '){
			if(input[i]>=65 && input[i]<=90){ // �빮�ڶ��, �ҹ��ڷ� ��ȯ( +32) 
				res[pos++] = input[i]+32;
				// A 65, a 97 
			}else{ // �ҹ��ڶ�� 
				res[pos++] = input[i];
			}
		}
	} 
	res[pos]= '\0'; //�������� NULL
	printf("%s\n", res); 
	
	return 0;
}


