#ifndef CHAINING_H
#define CHAINING_H
#pragma warning(disable : 4996) // strcpy() 

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // memset()

// 해시테이블 (체이닝) 

/* 
체이닝: 해시테이블 외부에 데이터를 저장하는 개방 해싱 알고리즘.

충돌을 고려하여 해시테이블이 링크드 리스트의 포인터를 관리한다. 

충돌이 발생하면 새 노드를 링크드리스트의 head에 붙인다. 
(tail 에 이어붙이려면, tail 찾다가 시간 소모하기 때문)

*/

typedef char* KeyType;
typedef char* ValueType; 

// linked list node
typedef struct tagNode {
	KeyType key;
	ValueType value;

	struct tagNode* next; // 다음 노드 
}Node;

// linked list (해시값이 같은 주소가 나오는 충돌이 발생해도 리스트에 이어붙인다.)
typedef Node* List;

// 해시테이블 
typedef struct tagHashTable {
	int tableSize;
	List* table;
}HashTable;


// Hash Table 생성/해제
HashTable*	CHT_CreateHashTable(int tableSize);
void		CHT_DestroyHashTable(HashTable* HT);

// Node 생성/해제
Node*		CHT_CreateNode(KeyType key, ValueType value);
void		CHT_DestoryNode(Node* target);
void		CHT_DestoryList(List list);

// [중요] 삽입, 탐색, 해시
void		CHT_Set(HashTable* HT, KeyType key, ValueType value);
ValueType	CHT_Get(HashTable* HT, KeyType key);
int			CHT_Hash(KeyType key, int keyLength, int tableSize);


/* 링크드 리스트에서 순차탐색이 아닌 이진탐색트리 활용해보기 */

#endif // !CHAINING_H