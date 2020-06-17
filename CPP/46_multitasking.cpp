#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

// 46. ��Ƽ�½�ŷ (īī�� �Թ湮�� ����) multitasking 

int main(int argc, char** argv){
	
	// �� ����, ���� ���� �ð�, ������, �� �۾� �ð�  
	int n, k, i, p=0, time=0, total = 0;
	
	//freopen("input.txt", "rt", stdin);
	
	scanf("%d", &n); // �Է� �ޱ� ����  
	
	vector<int> job(n+1); //�ε��� 1���� �̿�. 
	
	for(i=1; i<=n; i++){
		scanf("%d", &job[i]);
		total += job[i]; // �� �۾��� ���� ���д�.  
	}
	
	scanf("%d", &k); // ���� ���� �ð�.  // �Է� �ޱ� ��. 
	
	if(k >= total){ // �۾����� ���� ������ ���� �߻�. 
		printf("-1");
		return 0; 
	}
	
	while(1){
		p++; 
		
		if(p>n){
			p = 1;
		}
		
		if(job[p] != 0){ // �۾� �Ѵ�.  
			job[p]--;
			time++; // �۾��� �ϰ� �ð��� ������. 
			
			if(time == k){ // ���� �߻� ��, Ż��. 
				break; 
			} 
			
		}else{
			continue; // �ð��� ������ �ƴϴ�.   
		}
	}
	
	while(1){
		
		p++;
		if(p>n){
			p = 1;
		}	 
		
		if(job[p] != 0){
			break;
		} 
	} 
	
	printf("%d", p);
	
	return 0;
}


/*

īī�� �����α� '�Թ�'������ ������ ��. 45�� ���ֱ��ϱ� ������ ����� �ùķ��̼� ����. 

*/

