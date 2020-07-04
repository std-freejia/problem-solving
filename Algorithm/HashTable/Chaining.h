#ifndef CHAINING_H
#define CHAINING_H
#pragma warning(disable : 4996) // strcpy() 

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // memset()

// �ؽ����̺� (ü�̴�) 

/* 
ü�̴�: �ؽ����̺� �ܺο� �����͸� �����ϴ� ���� �ؽ� �˰���.

�浹�� ����Ͽ� �ؽ����̺��� ��ũ�� ����Ʈ�� �����͸� �����Ѵ�. 

�浹�� �߻��ϸ� �� ��带 ��ũ�帮��Ʈ�� head�� ���δ�. 
(tail �� �̾���̷���, tail ã�ٰ� �ð� �Ҹ��ϱ� ����)

*/

typedef char* KeyType;
typedef char* ValueType; 

// linked list node
typedef struct tagNode {
	KeyType key;
	ValueType value;

	struct tagNode* next; // ���� ��� 
}Node;

// linked list (�ؽð��� ���� �ּҰ� ������ �浹�� �߻��ص� ����Ʈ�� �̾���δ�.)
typedef Node* List;

// �ؽ����̺� 
typedef struct tagHashTable {
	int tableSize;
	List* table;
}HashTable;


// Hash Table ����/����
HashTable*	CHT_CreateHashTable(int tableSize);
void		CHT_DestroyHashTable(HashTable* HT);

// Node ����/����
Node*		CHT_CreateNode(KeyType key, ValueType value);
void		CHT_DestoryNode(Node* target);
void		CHT_DestoryList(List list);

// [�߿�] ����, Ž��, �ؽ�
void		CHT_Set(HashTable* HT, KeyType key, ValueType value);
ValueType	CHT_Get(HashTable* HT, KeyType key);
int			CHT_Hash(KeyType key, int keyLength, int tableSize);


/* ��ũ�� ����Ʈ���� ����Ž���� �ƴ� ����Ž��Ʈ�� Ȱ���غ��� */

#endif // !CHAINING_H