#include <iostream>
using namespace std;

// 3. 진약수의 합
// 자연수 N이 주어지면 자연수 N의 진약수의 합을 수식과 함께 출력하세요. 

int main(int argc, char** argv) {

	int n, i, sum=0;
	
	cin>>n;
	// 모든 수의 첫번째 약수는 1이다. 그래서 sum에 1을 더하고 시작. 
	cout<<"1";
	sum += 1;
	// "+약수" 패턴으로 출력해보자. 
	for(i=2; i<n; i++) {
		if(0 == n%i){ // 약수 발견, "+ 약수" 패턴으로 출력   
			cout<<"+"<<i;
			sum+=i;
		}
	}

	cout<<"="<<sum;

	return 0;
}

