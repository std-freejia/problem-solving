#include <iostream>
using namespace std;

// 2. 자연수의 합  
// 자연수 A,B가 주어지면 A부터 B까지의 합을 수식과 함께 출력하세요. 

int main(int argc, char** argv) {
	
	int a, b, i, sum = 0;
	// a 부터 b 까지. 
	cin>>a>>b;
	
	for(i=a; i<b; i++){
		cout<<i<<"+";
		sum += i;
	}
	// 마지막 수 출력과 = 출력. 
	cout<<i<<"=";
	// 전체 합 출력  
	cout<<sum+b;

	return 0;
}

