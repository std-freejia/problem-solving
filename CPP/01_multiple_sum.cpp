#include <iostream>
using namespace std;

// 1. 1���� N������ M�� �����  
int main(int argc, char** argv) {
	
	int n, m, i, sum = 0;
	// n�� m�� �Է¹޴´�.  
	cin >> n >> m;
	for (i=1; i<=n; i++){
		if(i%m == 0){
			sum+=i;
		} 
	}
	
	cout << sum;
	// ������ f9 
	// ���� f10
	return 0;
}
