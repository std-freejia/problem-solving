#include <string>
#include <vector>
using namespace std;

// �������� (���α׷��ӽ�) by std-freejia  

vector<int> rev(vector<int> begin){
	
	vector<int> temp;
	
	for(int i = begin.size() - 1; i >= 0; --i){
		temp.push_back(1 - begin[i]); // begin[i] ������ ���ڸ� �����´�.  001 -> 011
	}
	
	return temp; 
}

vector<int> solution(int n){
	
	vector<int> answer(1);
	
	if(n == 1) return answer;
	
	for(int i = 2; i <= n; ++i){
		
		vector<int> temp = rev(answer);
		answer.push_back(0); // ����� �ݵ�� 0  
		
		for(int j = 0; j < temp.size(); ++j){
			answer.push_back(temp[j]);
		}
	}
	
	return answer;
}
