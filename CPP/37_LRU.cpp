#include <stdio.h> 
#include <string.h>
#include <vector> 
#include <algorithm>
using namespace std;

// 37. Least Recently Used(īī�� ĳ�� ���� ����)

/*


* �Է¼��� 
ù ��° �ٿ� ĳ���� ũ���� S(3<=S<=10)�� �۾��� ���� N(5<=N<=1,000)�� �Էµȴ�.
�� ��° �ٿ� N���� �۾���ȣ�� ó�������� �־�����. �۾���ȣ�� 1 ~100 �̴�

* ��¼���
7 5 3 2 6
������ �۾� �� ĳ�ø޸��� ���¸� ���� �ֱ� ���� �۾����� ���ʷ� ����մϴ�

*/

// ���� § �ڵ�. 
 
int main(int argc, char** argv){
		
	int job_size, cache_size, newjob, i, j, m, flag = 0;
	
	//freopen("input.txt", "rt", stdin);
	
	scanf("%d %d", &cache_size, &job_size);

	vector<int> cache(cache_size);

	for(i=0; i<job_size; i++){ // cache�� �ִ´�. 
		
		scanf("%d", &newjob);

		flag = 0;
		
		for(j=0; j<cache_size; j++){ 
			
			if(newjob == cache[j]){ //  cache hit 
				flag = 1;
				break;	
			}
		} 
		
		if(flag){ // cache hit

			for(m=j; m>=1; m--){ //�ϳ��� ���������� �δ�. 
				cache[m] = cache[m-1];
			}

		}else{ // cache miss

			for(m=cache_size-1; m>=1; m--){ //�ϳ��� ���������� �δ�. 
				cache[m] = cache[m-1];
			}
			
		}
		
		cache[0] = newjob;
		
	}
	
	for(i=0; i<cache_size; i++){ // ��� 
	
		printf("%d ", cache[i]);
	} 
	 
	return 0;
}

/*

ĳ�� hit, miss �� ó���ϴ� �κ��� �����԰� �޶� �׵��� Ʋ�Ⱦ���. 
 
48 ���κ��� 60���� ���� ���� ������ ®�� �ڵ�� ������ ����. 

		if(flag){ // cache hit
			if(j == 0) break;
			
			for(m=j-1; m>=0; m--){ //�ϳ��� ���������� �δ�. 
				cache[m+1] = cache[m];
			}

		}else{ // cache miss
			
			for(m=cache_size-1; m>=0; m--){ //�ϳ��� ���������� �δ�. 
				cache[m+1] = cache[m];
			}
			
		} 

���ڸ� �ϳ��� �̴� for���� �ε����� Ʋ�Ⱦ���.  

*/ 

