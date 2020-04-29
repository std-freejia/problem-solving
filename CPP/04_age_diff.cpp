#include <iostream>
using namespace std;

// 4. 나이 차이  age_diff
// N명의 나이가 주어진다. 
// 가장 많은 나이와 가장 작은 나이의 차이를 출력하세요. 

int main(int argc, char** argv) {
	
	int totalNum, i, age;
	int maxAge = -2147000000; // int 가장 작은 수로 초기화
	int minAge = 2147000000; 
	
	cin >> totalNum; // 전체 사람 수 
	
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

