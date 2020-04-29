#include <iostream>
using namespace std;

// 1. 1부터 N까지의 M의 배수합  
int main(int argc, char** argv) {
	
	int n, m, i, sum = 0;
	// n과 m을 입력받는다.  
	cin >> n >> m;
	for (i=1; i<=n; i++){
		if(i%m == 0){
			sum+=i;
		} 
	}
	
	cout << sum;
	// 컴파일 f9 
	// 실행 f10
	return 0;
}
