#include <iostream>
using namespace std;

// 4. ���� ����  age_diff
// N���� ���̰� �־�����. 
// ���� ���� ���̿� ���� ���� ������ ���̸� ����ϼ���. 

/* input.txt
10
13 15 34 23 45 65 33 11 26 42
*/

int main(int argc, char** argv) {
	
	// ���������
	//freopen("input.txt", "rt", stdin); //read text option
	 
	int totalNum, i, age;
	int maxAge = -2147000000; // int ���� ���� ���� �ʱ�ȭ
	int minAge = 2147000000; 
	
	cin >> totalNum; // ��ü ��� �� 
	
	for(i=1; i<=totalNum; i++) {
		cin>>age;
		if(age>maxAge){  
			maxAge = age;
		}
		
		if(age<minAge){
			minAge = age;
		}
		
	}

	cout << maxAge-minAge;
	
	return 0;
}


